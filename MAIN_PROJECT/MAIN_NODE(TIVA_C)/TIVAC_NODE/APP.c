/*
 * APP.c
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */
#include "APP.h"

void  MCU_INIT(void)
{
    HC05_Init();
    SPI1_Init();
    PWM_INIT_PF1();
}

uint8 WaitForCommand(void)
{
    uint8 Number = UART5_ReceiveByte();
    return Number;
}

void  ExecuteCommand(uint8 cmd)
{
           switch(cmd)
           {
           case '1':

               Servo_Angle(180);
               UART5_SendString("Door is open!");

               break;

           case '2':

               Servo_Angle(0);
               UART5_SendString("Door is Closed!");

               break;

           case '3':

               SPI1_Send('3');

               break;

           case '4':

               SPI1_Send('4');


               break;

           case '5':

               SPI1_Send('5');


               break;

           case '6':

               SPI1_Send('6');


               break;


           default:

               UART5_SendString("Invalid Command!\n");

               break;
           }
}

void Run_App(void)
{
    uint8 cmd = WaitForCommand();
    if(cmd > '6' || cmd < '1')
    {
        return;
    }
    ExecuteCommand(cmd);
}
