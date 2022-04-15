//gcc��׼ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#include <pthread.h>

//hps �����ṩ�ĵײ㶨��ͷ�ļ�
#define soc_cv_av	//����ʹ��soc_cv_avӲ��ƽ̨

#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"

//���û�����HPSӦ��ϵͳ��ص�Ӳ������ͷ�ļ�
#include "hps_0.h"

#include "HAL_IF/uart.h"
#include "HAL_IF/hal_delay.h"
#include "HAL_IF/hal_spim.h"
#include "HAL_IO/HAL_IO.h"
#include "ad7799.h"
#include "CN0397.h"
#include "Server.h"

#define HW_REGS_BASE (ALT_STM_OFST )	//HPS�����ַ�λ���ַ
#define HW_REGS_SPAN (0x04000000 )		//HPS�����ַ�ε�ַ�ռ�
#define HW_REGS_MASK (HW_REGS_SPAN - 1 )	//HPS�����ַ�ε�ַ����

static volatile unsigned long *led_pio_virtual_base = NULL;	//led_pio�����ַ
static volatile unsigned long *button_pio_virtual_base = NULL;//button_pio�����ַ
extern unsigned long *uart_0_virtual_base;
//static volatile unsigned long *uart_0_virtual_base = NULL;	//uart_0�����ַ


int fpga_init(long int *virtual_base) {
	int fd;
	void *periph_virtual_base;	//����ռ������ַ

	//��MMU
	if ((fd = open("/dev/mem", ( O_RDWR | O_SYNC))) == -1) {
		printf("ERROR: could not open \"/dev/mem\"...\n");
		return (1);
	}

	//�������ַ��ӳ�䵽�û��ռ�
	periph_virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE),
	MAP_SHARED, fd, HW_REGS_BASE);
	if (periph_virtual_base == MAP_FAILED) {
		printf("ERROR: mmap() failed...\n");
		close(fd);
		return (1);
	}

	//ӳ��õ�led_pio���������ַ
	led_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + LED_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//ӳ��õ�button_pio���������ַ
	button_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + BUTTON_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//ӳ��õ�uart_0���������ַ
	uart_0_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + UART_0_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	*virtual_base = periph_virtual_base;	//�����������ַ���棬�����ͷ�ʱ��ʹ��
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
			button_pio_virtual_base[3] = 0xFF;	//��λ���ؼ��
			//����LED7
			led_pio_virtual_base[0] = 0x01<<6;

			while(1){
				button_edge = button_pio_virtual_base[3];

				if(button_edge & 0x01 == 0x01){
					button_pio_virtual_base[3] = 0xFF;	//��λ���ؼ��
					led_pio_virtual_base[0] = 0x00;
					break;
				}
				else if(button_edge == 0x02){
					button_pio_virtual_base[3] = 0xFF;	//��λ���ؼ��
					led_pio_virtual_base[0] = 0x03<<5;
					DataRecord();
					Delay(1000);
					led_pio_virtual_base[0] = 0x01<<6;
				}
			}
		}
		else{
			button_pio_virtual_base[3] = 0xFF;	//��λ���ؼ��
			//Ϩ��LED
			led_pio_virtual_base[0] = 0x00;
		}
	}

	//�����˳�ǰ��ȡ�������ַӳ��
	if (munmap(virtual_base, HW_REGS_SPAN) != 0) {
		printf("ERROR: munmap() failed...\n");
		close(fd);
		return (1);
	}

	//close(fd); //�ر�MMU
	return 0;
}

