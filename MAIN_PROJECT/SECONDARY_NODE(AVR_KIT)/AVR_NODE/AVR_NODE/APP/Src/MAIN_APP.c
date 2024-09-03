/*
 * MAIN_APP.c
 *
 * Created: 9/2/2024 5:44:11 PM
 *  Author: Administrator
 */ 
#include "MAIN_APP.h"

void MCU_INIT(void)
{
	DIO_Init(); //Initialize DIO Pins of Slave MCU
	SPI_ConfigTypes SPI_options = {Slave,MSB,SPIClock_64,DoupleSpeedDisable}; //Slave SPI Config Options
	SPI_Init(&SPI_options); //Initialize Slave SPI	
}

void MAIN_APP(void)
{
		u8 Received_From_Master = STD_Low;
		
		Received_From_Master = SPI_TxRx(Ack);
		
		switch(Received_From_Master)
		{
			case Led0:
			DIO_ToggleChannel(DIO_ChannelD3);
			break;
			
			case Led1:
			DIO_ToggleChannel(DIO_ChannelC2);
			break;
			
			case Led2:
			DIO_ToggleChannel(DIO_ChannelC7);
			break;
			
			case Air_Cond:
			DIO_ToggleChannel(DIO_ChannelA0);
			DIO_ToggleChannel(DIO_ChannelA1);
			DIO_ToggleChannel(DIO_ChannelA2);
			break;
			
			default:
			//Invalid choice
			//The code will never reach this part since the master node can not send insufficient data from the first place
			return;
			break;
		}	
}