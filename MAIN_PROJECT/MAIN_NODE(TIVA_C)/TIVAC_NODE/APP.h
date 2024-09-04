/*
 * APP.h
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */

#ifndef APP_H_
#define APP_H_

#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "UART5.h"
#include "SPI.h"
#include "PWM.h"

void  MCU_INIT(void);
uint8 WaitForCommand(void);
void  ExecuteCommand(uint8 cmd);
void  Run_App(void);

#endif /* APP_H_ */
