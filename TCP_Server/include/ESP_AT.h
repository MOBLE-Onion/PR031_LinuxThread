/*
 * @file	ESP_AT.h
 * @brief	functions to operate ESP8266 module using AT commands
 *
 *  Created on: 2022Äê3ÔÂ26ÈÕ
 *      Author: MOSYELIAN
 */

#ifndef TCP_SERVER_INCLUDE_ESP_AT_H_
#define TCP_SERVER_INCLUDE_ESP_AT_H_

enum AT_cmd{
	RST,
	Echo0,
	CWMODE_3,

	CWJAP,
	CIPSTART_TCP,
	CIPSTART_UDP,
	CIPMODE_1,
	CIPMODE_0,
	CIPSEND,

	CIPCLOSE,

	CIPMUX_1,
	CIPSERVER_1
};

int ESP_Init(void);
int ESP_Connect_WiFi(void);
int ESP_UDP_PassThrough_Init(void);
int ESP_UDP_PassThrough_DeInit(void);
int ESP_Tx(uint8_t* data, uint8_t* length);
int ESP_Rx(uint8_t* data, uint8_t* length);

#endif /* TCP_SERVER_INCLUDE_ESP_AT_H_ */
