/*! ------------------------------------------------------------------------------------------------------------------
 * @file    uart.h
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

#ifndef _UART_H_
#define _UART_H_

//gcc标准头文件
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

void uart_putc(char c, volatile unsigned long *UART_VB);
void uart_printf(char *str, volatile unsigned long *UART_VB);
char uart_getc(volatile unsigned long *UART_VB);
int uart_scanf(char *p, uint8_t n, volatile unsigned long *UART_VB);

#endif
