/*
 * DataRecord.c
 *
 *  Created on: 2022Äê3ÔÂ29ÈÕ
 *      Author: MOSYELIAN
 */

#include <stdint.h>
#include <sys/time.h>

#include "CN0397.h"
#include "Data_Log/data_log.h"
#include "DWM1001_host/dwm.h"

void DataRecord(void *arg)
{
	int32_t RGB_data[3];
	int32_t pos[3];
	uint8_t quality = 0;

	uint16_t i;
	int errno;
	uint16_t str_len = 0;
	char print_str[255];

	CN0397_ReadADCData(RGB_data);

	errno = snprintf(print_str, 255, "R_G_B data in mV: ");
	str_len = (errno >= 0)? strlen(print_str):0;
	for(i = 0; i < 3; i++){
	  errno = snprintf(print_str+str_len, 255-str_len, "%5d", RGB_data[i]);
	  str_len += (errno >= 0)? 5:0;
	}

	dwm_pos_get(pos, &quality);

	errno = snprintf(print_str+str_len, 255-str_len, "  Position in mm: ");
	str_len = (errno >= 0)? strlen(print_str):0;
	for(i = 0; i < 3; i++){
	  errno = snprintf(print_str+str_len, 255-str_len, "%10d", pos[i]);
	  str_len += (errno >= 0)? 10:0;
	}
	errno = snprintf(print_str+str_len, 255-str_len, "\n");

	Data_Log("%s", print_str);
}
