/*! ------------------------------------------------------------------------------------------------------------------
 * @file    uart.c
 * @brief	using virtual address to driver UART Device on FPGA side
 *
 *
 *
 * @attention
 *
 * Author: Liu Cong
 *
 * All rights reserved.
 *
 */

#include <stdint.h>

#include "uart.h"

//#define UART_VB uart_virtual_base

volatile unsigned long *uart_0_virtual_base = NULL;	//uart_0虚拟地址
volatile unsigned long *uart_1_virtual_base = NULL; //uart_1虚拟地址

//串口字符发送函数
void uart_putc(char c, volatile unsigned long *UART_VB) {
	unsigned short uart_status;	//状态寄存器值
	do {
		uart_status = *(UART_VB + 2);	//读取状态寄存器
	} while (!(uart_status & 0x40));	//等待状态寄存器bit6（trdy）为1

	*(UART_VB + 1) = c;	//发送一个字符
}

//串口字符串发送函数
void uart_printf(char *str, volatile unsigned long *UART_VB) {
	while (*str != '\0')	//检测当前指针指向的数是否为空字符
	{
		uart_putc(*str, UART_VB);	//发送一个字符
		str++;	//字符串指针+1
	}
}

//串口字符接收函数
char uart_getc(volatile unsigned long *UART_VB) {
	unsigned short uart_status;	//状态寄存器值
	do {
		uart_status = *(UART_VB + 2);	//读取状态寄存器
	} while (!(uart_status & 0x80));	//等待状态寄存器bit7（rrdy）为1

	return *(UART_VB + 0);	//读取一个字符并作为函数返回值返回
}

//串口字符串接收函数
int uart_scanf(char *p, uint8_t n, volatile unsigned long *UART_VB) {
	int cnt = 0;	//接收个数计数器
	while (1) {
		*p = uart_getc(UART_VB);	//读取一个字符的数据
		cnt++;
		if (cnt >= n)
			return cnt;	//换行则停止计数,返回当前接收的字符个数
		else
			p++;	//接收指针增1
	}
}
