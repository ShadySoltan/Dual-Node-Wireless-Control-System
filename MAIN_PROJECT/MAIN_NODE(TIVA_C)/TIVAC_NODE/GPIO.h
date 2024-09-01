/*
 * GPIO.h
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

#define RED_LED     1
#define BLUE_LED    2
#define GREEN_LED   3

void Leds_Init(void);
void LED_ON(uint8 LED);
void LED_OFF(uint8 LED);
void LED_TOGGLE(uint8 LED);
boolean Is_LED_ON(uint8 LED);

#endif /* GPIO_H_ */
