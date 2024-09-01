/*
 * SPI.c
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */
#include "SPI.h"

void SPI1_Init(void)
{
    SYSCTL_RCGCSSI_R |= 0x02;
    SYSCTL_RCGCGPIO_R |= 0x08;

    GPIO_PORTD_AFSEL_R |= (1 << SCK_PIN) | (1 << SS_PIN) | (1 << MISO_PIN) | (1 << MOSI_PIN);
    GPIO_PORTD_PCTL_R  |= (2 << (SCK_PIN * 4)) | (2 << (SS_PIN * 4)) | (2 << (MISO_PIN * 4)) | (2 << (MOSI_PIN * 4));
    GPIO_PORTD_DIR_R   |= (1 << SS_PIN);
    GPIO_PORTD_DEN_R   |= (1 << SCK_PIN) | (1 << SS_PIN) | (1 << MISO_PIN) | (1 << MOSI_PIN);

    //Configure SPI1 module
    SSI1_CR1_R  = 0;                                               //Disable SPI1 Module before configuration
    SSI1_CR1_R |= 0x00000004;                                      //Set SPI module as master
    SSI1_CR0_R  = 0x07;                                            //Set Data Size to be 8 bits
    SSI1_CPSR_R = 64;                                              //Set Clock prescale div to 64
    SSI1_CR1_R  = 0x02;                                            //Enable SPI1
}

void SPI1_Send(uint8 data)
{
    //wait until transmit FIFO is not full
    while((SSI1_SR_R & 0x02) == 0);

    //Write data to data Rister
    SSI1_DR_R = data;

    //wait until transmit is complete
    while((SSI1_SR_R & 0x10) == 0);
}

