/*
 * dw3000.c
 *
 *  Created on: Feb 27, 2026
 *      Author: Kewal
 */

#include "dw3000.h"


uint32_t checkCom(SPI_HandleTypeDef* spi) {
	// Reset
	HAL_GPIO_WritePin(RST_PORT, RST_PIN, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(RST_PORT, RST_PIN, GPIO_PIN_SET);
	HAL_Delay(5);

	uint8_t tx[5] = {0};
	uint8_t rx[5] = {0};


	tx[0] = 0x00;

	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(spi, tx, rx, 5, 100);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);

	uint32_t dev_id =
	  (rx[4] << 24) |
	  (rx[3] << 16) |
	  (rx[2] << 8)  |
	  (rx[1]);

	return dev_id;

}

void transmit(SPI_HandleTypeDef* spi, uint8_t reg, uint8_t* data, int len) {
	HAL_SPI_Transmit(spi, &reg, 1, TIMEOUT);
}

