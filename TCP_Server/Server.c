/*
 * Serve.c
 *
 *  Created on: 2022年3月28日
 *      Author: MOSYELIAN
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "Server.h"
#include "ESP_AT.h"
#include "../HAL_IF/hal_delay.h"

static char data_file_name[] = "data.txt";
static FILE *fp = NULL;

void* ServerFunc(void* arg)
{
	int ret = 0;

	printf("ServerFunction Running!\n");

//	ret = ESP_Connect_WiFi();
	ret = ESP_Init();
	ret = ESP_UDP_PassThrough_Init();
	printf("ESP OK!\n");

	uint8_t rx_str[10];
	uint8_t tx_str[32];
	uint8_t rx_length;
	uint8_t tx_length;
	while(1){
		rx_length = 10;
		ESP_Rx(rx_str, &rx_length);
		if(rx_length){	//get a request
			while(1){
				tx_length = ServerReadFile(tx_str, 10);		//读日志文件

				if(tx_length != 0){
					ret = ESP_Tx(tx_str, &tx_length);		//发送文件内容
					while(ret != 0){
						sleep(1);
						ret = ESP_Tx(tx_str, &tx_length);
					}
				}
				if(tx_length < 10){
					ServerCloseFile();
					break;
				}
			}
		}
		else
			sleep(1);
	}

	ret = ESP_UDP_PassThrough_DeInit();
	return (void *) ret;
}

/**
 * @brief get log file pointer.
 *        If log file not open yet, initializes the log file.
 *
 * @param none
 *
 * @return log file pointer
 */
FILE * ServerGetFile(void)
{
	if(fp != NULL){
		return fp;
	}

	fp = fopen(data_file_name, "r");

	return fp;
}

/**
 * @brief de-initializes the log file.
 *
 * @param none
 *
 * @return none
 */
void ServerCloseFile(void)
{
   if(fp != NULL)
   {
      fclose(fp);
      fp = NULL;
   }
}

/**
 * @brief get log file data.
 *        If log file not open yet, open the log file.
 *
 * @param
 *
 * @return	the number of bytes actually read,
 */
uint8_t ServerReadFile(uint8_t* data, uint8_t length)
{
	uint8_t ret = 0;

	ret = fread(data, 1, length, ServerGetFile());

	return ret;
}


