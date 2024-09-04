/*
 * UART5.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Administrator
 */
#include "UART5.h"

void HC05_Init(void)
{
    SYSCTL_RCGCUART_R |= 0x20;
    while(!(SYSCTL_PRUART_R & 0x20));

    SYSCTL_RCGCGPIO_R |= 0x10;
    while(!(SYSCTL_RCGCGPIO_R&0x10));

    UART5_CTL_R = 0;

    UART5_IBRD_R = 104;
    UART5_FBRD_R = 11;
    UART5_CC_R = 0;
    UART5_LCRH_R = 0x60;

    UART5_CTL_R = 0x301;

    GPIO_PORTE_AFSEL_R = 0x30;
    GPIO_PORTE_AMSEL_R = 0;
    GPIO_PORTE_PCTL_R = 0x00110000;
    GPIO_PORTE_DEN_R = 0x30;
}

void UART5_SendByte(uint8 data)
{
    // Ensure the transmit FIFO is empty before sending
    while(!(UART5_FR_R & UART5_FR_TXFE_MASK));  // Wait until transmit FIFO is empty

    // Transmit the byte
    UART5_DR_R = data;

    // Optional: Wait until transmission is complete (to flush TX FIFO)
    while(UART5_FR_R & 0x08);  // Wait until UART5 is no longer busy
}

uint8 UART5_ReceiveByte(void)
{
    // Optional: Clear the receive FIFO by reading any residual data
    while(UART5_FR_R & UART5_FR_RXFE_MASK);  // Wait for receive FIFO to have data

    // Receive and return the byte
    return UART5_DR_R;
}

void UART5_ReceiveString(uint8 *pData)
{
    uint32 uCounter = 0;

    pData[uCounter] = UART5_ReceiveByte();

    while(pData[uCounter] != '#')
    {
        uCounter++;
        pData[uCounter] = UART5_ReceiveByte();
    }
    pData[uCounter] = '\0';
}

void UART5_SendString(const uint8 *pData)
{
    uint32 uCounter = 0;

    while(pData[uCounter] != '\0')
    {
        UART5_SendByte(pData[uCounter]);
        uCounter++;
    }
}

