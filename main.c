//gcc标准头文件
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#include <pthread.h>

//hps 厂家提供的底层定义头文件
#define soc_cv_av	//定义使用soc_cv_av硬件平台

#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"

//与用户具体HPS应用系统相关的硬件描述头文件
#include "hps_0.h"

#include "HAL_IF/uart.h"
#include "HAL_IF/hal_delay.h"
#include "HAL_IF/hal_spim.h"
#include "HAL_IO/HAL_IO.h"
#include "ad7799.h"
#include "CN0397.h"
#include "Server.h"

#define HW_REGS_BASE (ALT_STM_OFST )	//HPS外设地址段基地址
#define HW_REGS_SPAN (0x04000000 )		//HPS外设地址段地址空间
#define HW_REGS_MASK (HW_REGS_SPAN - 1 )	//HPS外设地址段地址掩码

static volatile unsigned long *led_pio_virtual_base = NULL;	//led_pio虚拟地址
static volatile unsigned long *button_pio_virtual_base = NULL;//button_pio虚拟地址
extern unsigned long *uart_0_virtual_base;
//static volatile unsigned long *uart_0_virtual_base = NULL;	//uart_0虚拟地址


int fpga_init(long int *virtual_base) {
	int fd;
	void *periph_virtual_base;	//外设空间虚拟地址

	//打开MMU
	if ((fd = open("/dev/mem", ( O_RDWR | O_SYNC))) == -1) {
		printf("ERROR: could not open \"/dev/mem\"...\n");
		return (1);
	}

	//将外设地址段映射到用户空间
	periph_virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE),
	MAP_SHARED, fd, HW_REGS_BASE);
	if (periph_virtual_base == MAP_FAILED) {
		printf("ERROR: mmap() failed...\n");
		close(fd);
		return (1);
	}

	//映射得到led_pio外设虚拟地址
	led_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + LED_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//映射得到button_pio外设虚拟地址
	button_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + BUTTON_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//映射得到uart_0外设虚拟地址
	uart_0_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + UART_0_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	*virtual_base = periph_virtual_base;	//将外设虚拟地址保存，用以释放时候使用
	return fd;
}

int main(int argc, char ** argv)
{
	void* res;
	int fd;
	long int virtual_base;
	fd = fpga_init(&virtual_base);

	CN0397_Init();

	pthread_t ServerThread;
	pthread_create(&ServerThread, NULL, ServerFunc, "/dev/ttyS1");

	uint8_t button_edge;
	button_pio_virtual_base[3] = 0xFF;

	while(1){
		Delay(200);
		button_edge = button_pio_virtual_base[3];

		if(button_edge == 0x1){
			button_pio_virtual_base[3] = 0xFF;	//复位边沿检测
			//点亮LED7
			led_pio_virtual_base[0] = 0x01<<6;

			while(1){
				button_edge = button_pio_virtual_base[3];

				if(button_edge & 0x01 == 0x01){
					button_pio_virtual_base[3] = 0xFF;	//复位边沿检测
					led_pio_virtual_base[0] = 0x00;
					break;
				}
				else if(button_edge == 0x02){
					button_pio_virtual_base[3] = 0xFF;	//复位边沿检测
					led_pio_virtual_base[0] = 0x03<<5;
					DataRecord();
					Delay(1000);
					led_pio_virtual_base[0] = 0x01<<6;
				}
			}
		}
		else{
			button_pio_virtual_base[3] = 0xFF;	//复位边沿检测
			//熄灭LED
			led_pio_virtual_base[0] = 0x00;
		}
	}

	//程序退出前，取消虚拟地址映射
	if (munmap(virtual_base, HW_REGS_SPAN) != 0) {
		printf("ERROR: munmap() failed...\n");
		close(fd);
		return (1);
	}

	//close(fd); //关闭MMU
	return 0;
}

