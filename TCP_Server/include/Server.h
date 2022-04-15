/*
 * Server.h
 *
 *  Created on: 2022��3��28��
 *      Author: MOSYELIAN
 */

#ifndef TCP_SERVER_INCLUDE_SERVER_H_
#define TCP_SERVER_INCLUDE_SERVER_H_

void* ServerFunc(void* arg);
FILE * ServerGetFile(void);
void ServerCloseFile(void);
uint8_t ServerReadFile(uint8_t* data, uint8_t length);

#endif /* TCP_SERVER_INCLUDE_SERVER_H_ */
