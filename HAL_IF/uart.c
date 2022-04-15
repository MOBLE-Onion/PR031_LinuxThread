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

volatile unsigned long *uart_0_virtual_base = NULL;	//uart_0�����ַ
volatile unsigned long *uart_1_virtual_base = NULL; //uart_1�����ַ

//�����ַ����ͺ���
void uart_putc(char c, volatile unsigned long *UART_VB) {
	unsigned short uart_status;	//״̬�Ĵ���ֵ
	do {
		uart_status = *(UART_VB + 2);	//��ȡ״̬�Ĵ���
	} while (!(uart_status & 0x40));	//�ȴ�״̬�Ĵ���bit6��trdy��Ϊ1

	*(UART_VB + 1) = c;	//����һ���ַ�
}

//�����ַ������ͺ���
void uart_printf(char *str, volatile unsigned long *UART_VB) {
	while (*str != '\0')	//��⵱ǰָ��ָ������Ƿ�Ϊ���ַ�
	{
		uart_putc(*str, UART_VB);	//����һ���ַ�
		str++;	//�ַ���ָ��+1
	}
}

//�����ַ����պ���
char uart_getc(volatile unsigned long *UART_VB) {
	unsigned short uart_status;	//״̬�Ĵ���ֵ
	do {
		uart_status = *(UART_VB + 2);	//��ȡ״̬�Ĵ���
	} while (!(uart_status & 0x80));	//�ȴ�״̬�Ĵ���bit7��rrdy��Ϊ1

	return *(UART_VB + 0);	//��ȡһ���ַ�����Ϊ��������ֵ����
}

//�����ַ������պ���
int uart_scanf(char *p, uint8_t n, volatile unsigned long *UART_VB) {
	int cnt = 0;	//���ո���������
	while (1) {
		*p = uart_getc(UART_VB);	//��ȡһ���ַ�������
		cnt++;
		if (cnt >= n)
			return cnt;	//������ֹͣ����,���ص�ǰ���յ��ַ�����
		else
			p++;	//����ָ����1
	}
}
