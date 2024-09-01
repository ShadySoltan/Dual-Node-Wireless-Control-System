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

//Commands
#define OPEN_DOOR          '1'
#define CLOSE_DOOR         '2'
#define TOGGLE_LED0        '3'
#define TOGGLE_LED1        '4'
#define TOGGLE_LED2        '5'
#define TOGGLE_AC          '6'

void  MCU_INIT(void);
uint8 WaitForCommand(void);
void  ExecuteCommand(uint8 cmd);
void  TransferCommand(uint8 cmd);
void  RUN_APP(void);

#endif /* APP_H_ */
