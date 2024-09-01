/*
 * GPIO.c
 *
 *  Created on: Sep 1, 2024
 *      Author: Administrator
 */
#include "GPIO.h"

void Leds_Init(void)
{
    //GPIO PORTF Clock
    SYSCTL_RCGCGPIO_R |= 0x20;
    while(!(SYSCTL_PRGPIO_R & 0x20));

    //Disable Analog for the 3 leds
    GPIO_PORTF_AMSEL_R &= 0xF1;
    //Choose GPIO mode
    GPIO_PORTF_PCTL_R &= 0xFFFF000F;
    //Configure the direction for the three leds to be output
    GPIO_PORTF_DIR_R |= 0x0E;
    //Disable Alternate function for the three PINS
    GPIO_PORTF_AFSEL_R &= 0xF1;
    //Enable digital I/O for the three PINS
    GPIO_PORTF_DEN_R |= 0x0E;
    //Disable All three Leds
    GPIO_PORTF_DATA_R &= 0xF1;
}

void LED_ON(uint8 LED)
{
    if(LED == 1 || LED == 2 || LED == 3)
    {
        SetBit(GPIO_PORTF_DATA_R,LED);
    }
    else
    {
        return;
    }
}

void LED_OFF(uint8 LED)
{
    if(LED == 1 || LED == 2 || LED == 3)
    {
        ClearBit(GPIO_PORTF_DATA_R,LED);
    }
    else
    {
        return;
    }
}

void LED_TOGGLE(uint8 LED)
{
    if(LED == 1 || LED == 2 || LED == 3)
    {
        ToggleBit(GPIO_PORTF_DATA_R,LED);
    }
    else
    {
        return;
    }
}

boolean Is_LED_ON(uint8 LED)
{
    boolean value = FALSE;
    if(LED == 1 || LED == 2 || LED == 3)
    {
        value = (boolean)(GetBit(GPIO_PORTF_DATA_R,LED));
    }
    else
    {
        //Do Nothing;
    }

    return value;
}
