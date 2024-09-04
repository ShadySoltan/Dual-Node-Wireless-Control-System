/*
 * SPI.h
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */

#ifndef SPI_H_
#define SPI_H_

#include "tm4c123gh6pm.h"


#define SS_PIN                                      1
#define SCK_PIN                                     0
#define MOSI_PIN                                    3
#define MISO_PIN                                    2


void SPI1_Init(void);
void SPI1_Send(uint8 data);


#endif /* SPI_H_ */
