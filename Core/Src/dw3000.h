/*
 * dw3000.h
 *
 *  Created on: Feb 27, 2026
 *      Author: Kewal
 */

#ifndef SRC_DW3000_H_
#define SRC_DW3000_H_

#include "stm32l4xx_hal.h"

#define TIMEOUT 100

#define RST_PIN GPIO_PIN_4
#define RST_PORT GPIOA

#define CS_PIN GPIO_PIN_5
#define CS_PORT GPIOA


// Checks if the SPI communication with the DW3000 device is available
// Returns 0 if communication fails
// Returns device ID if communication is successful
uint32_t checkCom(SPI_HandleTypeDef* spi);

// Transmits len number of bytes to reg
void transmit(SPI_HandleTypeDef* spi, uint8_t reg, uint8_t* data, int len);


#endif /* SRC_DW3000_H_ */
