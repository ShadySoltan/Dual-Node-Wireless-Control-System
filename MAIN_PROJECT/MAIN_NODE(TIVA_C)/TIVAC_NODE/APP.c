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
    uint8 cmd = UART5_ReceiveByte();
    return cmd - '0';
}

void  ExecuteCommand(uint8 cmd)
{
    delay(5000);
    switch(cmd)
    {
    case OPEN_DOOR:
        Servo_Angle(180);
        UART5_SendString("Door Opened!");
        break;

    case CLOSE_DOOR:
        Servo_Angle(0);
        UART5_SendString("Door Closed!");
        break;

    case TOGGLE_LED0:
    case TOGGLE_LED1:
    case TOGGLE_LED2:
    case TOGGLE_AC:
        TransferCommand(cmd);
        break;

    default:
            UART5_SendString("Invalid Command!\n");
        break;
    }
}

void  TransferCommand(uint8 cmd)
{
    SPI1_Send(cmd);
}

void  RUN_APP(void)
{
    uint8 cmd = WaitForCommand();
    ExecuteCommand(cmd);
}
