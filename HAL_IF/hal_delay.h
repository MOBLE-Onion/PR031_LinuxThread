/*
 * hal_delay.h
 *
 *  Created on: 2022Äê3ÔÂ26ÈÕ
 *      Author: MOSYELIAN
 */

#ifndef _HAL_DELAY_H_
#define _HAL_DELAY_H_

#include <sys/time.h>

float Time_Diff(struct timeval *start, struct timeval *end);
int Delay(int time_ms);

#endif /* _HAL_DELAY_H_ */
