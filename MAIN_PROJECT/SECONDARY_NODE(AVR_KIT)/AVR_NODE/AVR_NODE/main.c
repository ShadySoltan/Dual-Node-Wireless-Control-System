/*
 * AVR_NODE.c
 *
 * Created: 8/31/2024 4:33:52 PM
 * Author : Administrator
 */ 

#include "MAIN_APP.h"

int main(void)
{
	MCU_INIT();
    while (1) 
    {
		MAIN_APP();
    }
}

