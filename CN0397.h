#ifndef CN0397_H_
#define CN0397_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

bool _enter;   // enter key

#define REGISTERS_VALUES     3
#define CONVERSION_DATA      4

#define YES       1
#define NO        0

#define CHANNELS  3
#define G_Channel 0
#define R_Channel 1
#define B_Channel 2

#define V_REF                3300.0    // [mV]
#define _2_16                65535.0   // 2^16
#define spi_mode_3		3
#define spi_bits		8
#define spi_delay		0
#define spi_speed_Hz	2000000

extern int 	CN0397_Init(void);
extern void CN0397_DisplayData(void);
void CN0397_ReadADCData(int32_t *adcData);
extern void CN0397_ConvertToVoltage(uint16_t adcValue, float *voltage);
extern void CN0397_CalcLightIntensity(uint8_t channel, uint16_t adcValue, float *intensity);
extern void CN0397_CalcLightConcentration(uint8_t channel, float intensity, float *conc);
extern void CN0397_SetAppData(void);
extern void CN0397_Calibration(uint8_t channel);
extern void CN0397_SetBar(float conc, int *line);

/* Available settings:
 *  AD7798_GAIN_1, AD7798_GAIN_2,
 *  AD7798_GAIN_4, AD7798_GAIN_8,
 *  AD7798_GAIN_16, AD7798_GAIN_32,
 *  AD7798_GAIN_64, AD7798_GAIN_128
 */
#define ADC_GAIN      AD7798_GAIN_1
/* Available settings:
 * Check available value from datasheet
 */
#define ADC_SPS        0x05  //50SPS


/* Available settings:
 * How often to display output values on terminal -> msec
 */
#define DISPLAY_REFRESH        500   //[msec]

#define USE_CALIBRATION   YES    // Set YES if you want to use system zero-scale calibration before reading the system data; otherwise set NO.

#endif /* CN0397_H_ */
