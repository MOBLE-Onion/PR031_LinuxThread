/*! ------------------------------------------------------------------------------------------------------------------
 * @file    hal_spi.h
 * @brief   utility to operate spi device based on Linux system
 *
 * @attention
 *
 * Copyright 2017 (c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */
#ifndef _HAL_SPIM_H_
#define _HAL_SPIM_H_

#include <stdint.h>

#define HAL_SPI_MAX_LENGTH           255
#define HAL_SPI_MAX_PRINT_LENGTH     HAL_SPI_MAX_LENGTH*3
#define HAL_SPI_WAIT_PERIOD          1

#define HAL_SPI_DEV327660 0
#define HAL_SPI_DEV327661 1

/**
 * @struct spi_desc
 * @brief  SPI Descriptor
 */
struct spi_desc{
	char *dev_str;
	int spi_fd;
};

/**
 * @struct spi_init_param
 * @brief  SPI initial parameters
 */
struct spi_init_param{
	uint8_t mode;
	uint8_t bits;
	uint32_t speed;
	uint16_t delay;
};


/** 
 * @brief initializes the current SPI device, default /dev/spidev0.0
 *        use HAL_SPI_Sel to set current spi device
 *        use HAL_SPI_Which to get current spi device
 *
 * @param none
 *
 * @return Error code
 */
int HAL_SPI_Init(struct spi_desc *spi_desc, const struct spi_init_param *spi_initparam);

/** 
 * @brief de-initializes the current SPI device
 *
 * @param none
 *
 * @return none
 */
int HAL_SPI_DeInit(struct spi_desc *spi_desc);

/** 
 * @brief set current spi device
 *
 * @param [in] spi dev number, 0 or 1
 *
 * @return none
 */
void HAL_SPI_Sel(int dev);

/** 
 * @brief set current spi device
 *
 * @param none
 *
 * @return current spi device
 */
int HAL_SPI_Which(void);

/** 
 * @brief transmit data of length over the current SPI device
 *
 * @param [in] data: pointer to the TX data
 * @param [in] length: length of data to be transmitted
 *
 * @return Error code
 */
int HAL_SPI_Tx(struct spi_desc *spi_desc, uint8_t* data, uint8_t* length);

/** 
 * @brief receive data of length over the current SPI device
 *
 * @param [in] data: pointer to the RX data buffer
 * @param [in] length: length of data to be received
 *
 * @return Error code
 */
int HAL_SPI_Rx(struct spi_desc *spi_desc, uint8_t* rx_data, uint8_t* length);

/**
 * @brief Write to Communication Register and Read from specified register
 *
 * @param [in] spi_desc:
 * @param [in] buff:
 * @param [in] length:
 *
 * @return Error code
 */
int HAL_SPI_Wr_And_Rd(struct spi_desc* spi_desc, uint8_t* buff, uint8_t length);

#endif //_HAL_SPIM_H_

