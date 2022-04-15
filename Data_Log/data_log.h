/*! ------------------------------------------------------------------------------------------------------------------
 * @file    data_log.h
 * @brief   utility print to data file
 *
 */

#ifndef _DATA_LOG_H_
#define _DATA_LOG_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief get log file pointer.
 *        If log file not open yet, initializes the log file.
 *
 * @param none
 *
 * @return log file pointer
 */
FILE * Data_Log_GetFile(void);

/**
 * @brief de-initializes the log file.
 *
 * @param none
 *
 * @return none
 */
void Data_Log_DeInit(void);

/**
 * @brief prints formated args into log file.
 *
 * @param[in] formated args
 *
 * @return none
 */
void Data_Log(const char* format, ... );

#endif //_DATA_LOG_H_
