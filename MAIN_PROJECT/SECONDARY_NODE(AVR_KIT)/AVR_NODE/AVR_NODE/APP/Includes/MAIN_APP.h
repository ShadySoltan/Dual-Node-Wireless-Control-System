/*
 * MAIN_APP.h
 *
 * Created: 9/2/2024 5:43:59 PM
 *  Author: Administrator
 */ 


#ifndef MAIN_APP_H_
#define MAIN_APP_H_

#include "Clock.h"
#include "STD_Types.h"
#include "BitMath.h"
#include "SPI.h"
#include "DIO.h"
#include <avr/io.h>

#define Led0		3		
#define Led1		4
#define Led2		5
#define Air_Cond	6
#define Ack			0x01

void MCU_INIT(void);
void MAIN_APP(void);

#endif /* MAIN_APP_H_ */