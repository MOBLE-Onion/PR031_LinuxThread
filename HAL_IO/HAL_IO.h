/*
 * HAL_IO.h
 * @brief	definition of I/O devices and their operation functions
 *
 *  Created on: 2022Äê3ÔÂ28ÈÕ
 *      Author: MOSYELIAN
 */

#ifndef HAL_IO_HAL_IO_H_
#define HAL_IO_HAL_IO_H_

#include <stdint.h>

enum dir{
	input = 1,
	output = 2
};

struct IO_device{
	enum dir 	dir;
	uint8_t 	width;	//should less than 32 bits
	uint32_t*	addr_base;
};

/*
 * @brief	initialize IO pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Init(struct IO_device* IO_device, struct IO_device* init_param);

/*
 * @brief	take data from input pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Rx(struct IO_device* io_dev, uint32_t* data);

/*
 * @brief	send data to output pins
 *
 * @return	0 in case of success, negative error code otherwise.
 */
int IO_Tx(struct IO_device* io_dev, uint32_t* data);

#endif /* HAL_IO_HAL_IO_H_ */
