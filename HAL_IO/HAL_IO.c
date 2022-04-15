/*
 * HAL_IO.c
 *
 *  Created on: 2022Äê3ÔÂ28ÈÕ
 *      Author: MOSYELIAN
 */

#include "HAL_IO.h"

/*
 * @brief	initialize IO pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Init(struct IO_device* IO_device, struct IO_device* init_param)
{
	IO_device->addr_base = init_param->addr_base;
	IO_device->dir = init_param->dir;
	IO_device->width = init_param->width;

	return 0;
}

/*
 * @brief	take data from input pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Rx(struct IO_device* io_dev, uint32_t* data)
{
	if(io_dev->dir == output){
		return -1;
	}

	*data = *(io_dev->addr_base);
	return 0;
}

/*
 * @brief	send data to output pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Tx(struct IO_device* io_dev, uint32_t* data)
{
	if(io_dev->dir == input){
		return -1;
	}

	*(io_dev->addr_base) = *data;
	return 0;
}
