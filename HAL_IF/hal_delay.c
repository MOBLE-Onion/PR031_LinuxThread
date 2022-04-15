/*
 * hal_delay.c
 *
 *  Created on: 2022Äê3ÔÂ26ÈÕ
 *      Author: MOSYELIAN
 */

#include <stddef.h>

#include "hal_delay.h"

/**
 * @brief:	For time difference
 *
 */
float Time_Diff(struct timeval *start, struct timeval *end){
	return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

/**
 * @brief:	Delay some time
 *
 */
int Delay(int time_ms) {
	struct timeval start;
	struct timeval end;
	float PassTime = 0;
	float T = time_ms/1000.00;
	gettimeofday(&start, NULL);

	while(PassTime < T){
		gettimeofday(&end, NULL);
		PassTime = Time_Diff(&start, &end);
	}
	return 0;
}
