/*
 * dwm.c
 *
 *  Created on: 2022Äê3ÔÂ30ÈÕ
 *      Author: MOSYELIAN
 */

#include <stdint.h>

#include "../HAL_IF/uart.h"

extern unsigned long *uart_0_virtual_base;

int dwm_pos_get(int32_t* pos, uint8_t* quality)
{
	uint16_t i;
	uint8_t rxdata[20] = {0x2, 0x0};
	int32_t x, y, z;

	for(i=0; i<2; i++)
		uart_putc(rxdata[i], uart_0_virtual_base);

	uart_scanf(rxdata, 18, uart_0_virtual_base);

	x = *(int32_t *)(rxdata+5);
	y = *(int32_t *)(rxdata+9);
	z = *(int32_t *)(rxdata+13);

	*pos = x;
	*(pos+1) = y;
	*(pos+2) = z;
	*quality = rxdata[17];

	return 0;
}
