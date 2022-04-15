/*! ------------------------------------------------------------------------------------------------------------------
 * @file    data_log.h
 * @brief   utility print to data file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "data_log.h"

static char data_file_name[] = "data.txt";
static FILE *fp = NULL;

/**
 * @brief get log file pointer.
 *        If log file not open yet, initializes the log file.
 *
 * @param none
 *
 * @return log file pointer
 */
FILE * Data_Log_GetFile(void)
{
	if(fp != NULL){
		return fp;
	}

	fp = fopen(data_file_name, "a+");

	return fp;
}

/**
 * @brief de-initializes the log file.
 *
 * @param none
 *
 * @return none
 */
void Data_Log_DeInit(void)
{
   if(fp != NULL)
   {
      fclose(fp);
      fp = NULL;
   }
}

/**
 * @brief print log to data.txt file.
 *
 * @param formated strings
 *
 * @return none
 */
void Data_Log(const char* format, ... )
{
   va_list args;
   va_start( args, format );
   vfprintf( Data_Log_GetFile(), format, args );
   va_end( args );
   fflush(Data_Log_GetFile());
}

