/*
 * Server.h
 *
 *  Created on: 2022Äê3ÔÂ28ÈÕ
 *      Author: MOSYELIAN
 */

#ifndef TCP_SERVER_INCLUDE_SERVER_H_
#define TCP_SERVER_INCLUDE_SERVER_H_

void* ServerFunc(void* arg);
FILE * ServerGetFile(void);
void ServerCloseFile(void);
uint8_t ServerReadFile(uint8_t* data, uint8_t length);

#endif /* TCP_SERVER_INCLUDE_SERVER_H_ */
