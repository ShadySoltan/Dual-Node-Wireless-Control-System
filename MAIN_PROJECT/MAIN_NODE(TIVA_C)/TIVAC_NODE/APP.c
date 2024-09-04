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
    Number = UART5_ReceiveByte();
    return Number;
}

void  ExecuteCommand(uint8 cmd)
{
           switch(cmd)
           {
           case '1':
               if(GetBit(GPIO_PORTF_DATA_REG,1) == 0)
               {
                   UART5_SendString("LED0-SLAVE-ON");
                   SetBit(GPIO_PORTF_DATA_REG,1);

                   SPI1_Send('1');
               }
               else
               {
                   UART5_SendString("LED0-SLAVE-OFF");
                   ClearBit(GPIO_PORTF_DATA_REG,1);

                   SPI1_Send('1');
               }

               break;

           case '2':
               if(GetBit(GPIO_PORTF_DATA_REG,2) == 0)
               {
                   UART5_SendString("LED1-SLAVE-ON");
                   SetBit(GPIO_PORTF_DATA_REG,2);

                   SPI1_Send('2');
               }
               else
               {
                   UART5_SendString("LED1-SLAVE-OFF");
                   ClearBit(GPIO_PORTF_DATA_REG,2);

                   SPI1_Send('2');
               }
               break;

           case '3':
               if(GetBit(GPIO_PORTF_DATA_REG,3) == 0)
               {
                   UART5_SendString("LED2-SLAVE-ON");
                   SetBit(GPIO_PORTF_DATA_REG,3);

                   SPI1_Send('3');
               }
               else
               {
                   UART5_SendString("LED2-SLAVE-OFF");
                   ClearBit(GPIO_PORTF_DATA_REG,3);

                   SPI1_Send('3');
               }
               break;

           case '0':
               UART5_SendString("All LEDs OFF!");
               GPIO_PORTF_DATA_REG = (GPIO_PORTF_DATA_REG & 0xF1) | ((Number - '0')<<1);

               SPI1_Send('0');
               break;
           }
}
