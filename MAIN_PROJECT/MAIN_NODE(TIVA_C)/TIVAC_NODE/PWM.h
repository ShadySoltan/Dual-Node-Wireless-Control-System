/*
 * PWM.h
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */

#ifndef PWM_H_
#define PWM_H_

#include "tm4c123gh6pm.h"

#define Max_Count 650
#define Min_Count 100
#define Max_Angle 180
#define Min_Angle 0

void delay(uint32 d);
void PWM_INIT_PF1(void);
unsigned int convertArrayToInt(uint8* array);
void Servo_Angle(int Angle);


#endif /* PWM_H_ */
