/*! ------------------------------------------------------------------------------------------------------------------
 * @file    CN0397.c
 * @brief   utility to operate CN0397 boards based on spi interface
 *
 * @attention
 *
 *
 */

#include "CN0397.h"
#include "ad7799.h"

static struct ad7799_dev CN0397;
static struct spi_desc CN0397_SpiDesc;
static struct ad7799_init_param CN0397_param;
/**
 * @brief Initialize the Cn0397 board.
 *
 * @return 0 in case of success, negative error code otherwise.
 */
int CN0397_Init(void)
{
	int ret;

	CN0397_SpiDesc.dev_str = "/dev/spidev32766.0";
	CN0397.spi_desc = &CN0397_SpiDesc;

	CN0397_param.chip_type = ID_AD7798;
	CN0397_param.polarity = AD7799_UNIPOLAR;
	CN0397_param.gain = AD7799_GAIN_1;
	CN0397_param.vref_mv = V_REF;
	CN0397_param.precision = AD7799_PRECISION_MV;
	CN0397_param.spi_init.mode = spi_mode_3;
	CN0397_param.spi_init.bits = spi_bits;
	CN0397_param.spi_init.delay = spi_delay;
	CN0397_param.spi_init.speed = spi_speed_Hz;

	ret = ad7799_init(&CN0397, &CN0397_param);
	if(ret){
		printf("CN0397 initialization failure\n");
		return ret;
	}

	return ret;
}

void CN0397_ReadADCData(int32_t *adcData)
{
	ad7799_read_channel(&CN0397, R_Channel, adcData);
	ad7799_read_channel(&CN0397, G_Channel, adcData+1);
	ad7799_read_channel(&CN0397, B_Channel, adcData+2);
}




