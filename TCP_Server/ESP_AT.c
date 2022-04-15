/*
 * @file	ESP_AT.h
 * @brief	functions to operate ESP8266 module using AT commands
 *
 *  Created on: 2022Äê3ÔÂ26ÈÕ
 *      Author: MOSYELIAN
 */

#include <stdint.h>
#include <string.h>

#include "ESP_AT.h"
#include "../HAL_IF/hal_uart.h"
#include "../HAL_IF/hal_delay.h"

/*****************************************************************************/
/***************************** Constant definition ***************************/
/*****************************************************************************/
static const char* AT_plus[] = {
		[RST] 		= "AT+RST\r\n",
		[Echo0] 	= "ATE0\r\n",
		[CWMODE_3] 	= "AT+CWMODE=3\r\n",

		[CWJAP] = "AT+CWJAP=\"RTLS\",\"RTLSRTLS\"\r\n",
		[CIPSTART_TCP] = "AT+CIPSTART=\"TCP\",\"192.168.1.117\",8080\r\n",
		[CIPSTART_UDP] = "AT+CIPSTART=\"UDP\",\"192.168.1.117\",8080,8080,0\r\n",

		[CIPMODE_1] = "AT+CIPMODE=1\r\n",
		[CIPMODE_0] = "AT+CIPMODE=0\r\n",
		[CIPSEND] = "AT+CIPSEND\r\n",

		[CIPCLOSE] = "AT+CIPCLOSE\r\n",
};

/**
 * @brief ESP8266 initialized
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_Init(void)
{
	int ret;
	uint8_t length;

	ret = HAL_UART_Init();
	if(ret) {
		return -1;
	}

	length = strlen(AT_plus[RST]);
	ret = HAL_UART_Tx(AT_plus[RST], &length);
	Delay(5000);

	length = strlen(AT_plus[Echo0]);
	ret = HAL_UART_Tx(AT_plus[Echo0], &length);
	Delay(500);
	length = strlen(AT_plus[CWMODE_3]);
	ret = HAL_UART_Tx(AT_plus[CWMODE_3], &length);
	Delay(500);


	return ret;
}

/**
 * @brief Connect to WiFi
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_Connect_WiFi(void)
{
	int ret;
	uint8_t length;

	length = strlen(AT_plus[CWJAP]);
	ret = HAL_UART_Tx(AT_plus[CWJAP], &length);
	Delay(5000);

	return ret;
}

/**
 * @brief create a UDP UART-WiFi passthrough transmission
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_UDP_PassThrough_Init(void)
{
	int ret;
	uint8_t length;

	length = strlen(AT_plus[CIPSTART_UDP]);
	ret = HAL_UART_Tx(AT_plus[CIPSTART_UDP], &length);
	Delay(1000);

	length = strlen(AT_plus[CIPMODE_1]);
	ret = HAL_UART_Tx(AT_plus[CIPMODE_1], &length);
	Delay(500);

	length = strlen(AT_plus[CIPSEND]);
	ret = HAL_UART_Tx(AT_plus[CIPSEND], &length);
	Delay(500);

	return ret;
}

/**
 * @brief Quit a UDP UART-WiFi passthrough transmission
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_UDP_PassThrough_DeInit(void)
{
	int ret;
	uint8_t length;

	Delay(100);
	length = 3;
	ret = HAL_UART_Tx("+++", &length);
	Delay(200);

	length = strlen(AT_plus[CIPMODE_0]);
	ret = HAL_UART_Tx(AT_plus[CIPMODE_0], &length);
	Delay(200);

	length = strlen(AT_plus[CIPCLOSE]);
	ret = HAL_UART_Tx(AT_plus[CIPCLOSE], &length);
	Delay(200);

	return ret;
}

/**
 * @brief ESP_Tx
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_Tx(uint8_t* data, uint8_t* length){
	int ret;

	ret = HAL_UART_Tx(data, length);

	return ret;
}

/**
 * @brief ESP_Rx
 *
 * @param none
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int ESP_Rx(uint8_t* data, uint8_t* length){
	int ret;

	ret = HAL_UART_Rx(data, length);
	HAL_UART_Flush();

	return ret;
}


















