/*
 * PS3class.cpp
 *
 *  Created on: 2018/08/20
 *      Author: —T‘¿
 */
#include "Libraries/PS3/PS3class.hpp"
#include "Libraries/DefineLED.h"
#include "Libraries/DefineOrder.h"
#include "i2c.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[8];



 void PS3controller::SetconData()
 {
 	if(RXmsg.ExtId==(0x75))
 	{
 		for(int i=0;i<8;i++)
 		{
 			Data[i]=RxFIFO_Data[i];
 		}
 	}
 }

 void PS3controller::SendRequest()
 {
   while(TXok==false)
   {
//	if(  HAL_I2C_Master_Transmit(&hi2c2,CON_ADDRESEE, 0, 0,10)!=0)
//	{
//		ERROR_LED;
//	}
	if(canbus->Send((0x74),0,0)!=0)
	   {
		   ERROR_LED;
	   }
	else
	{
		if(tx_led>15)
		{
		TOGGLE_TX_LED;
		tx_led=0;
		}
		else
		{
			tx_led++;
		}
		TXok=true;
	}
   }
   TXok=false;
 }
short PS3controller::Maskbyte(int matrixnum,int shiftnum)
{
	return (Data[matrixnum]>>shiftnum)&0x1;
}

short PS3controller::SELECT()
{
	return (short)Maskbyte(0,0);
}

short PS3controller::L3(){
	return (short)Maskbyte(0,1);
}

short PS3controller::R3(){
	return (short)Maskbyte(0,2);
}
short PS3controller::START(){
	return (short)Maskbyte(0,3);
}
short PS3controller::UP(){
	return (short)Maskbyte(0,4);
}

short PS3controller::RIGHT(){
	return (short)Maskbyte(0,5);
}
short PS3controller::DOWN(){
	return (short)Maskbyte(0,6);
}
short PS3controller::LEFT(){
	return (short)Maskbyte(0,7);
}


short PS3controller::L1(){
	return (short)Maskbyte(1,2);
}
short PS3controller::R1(){
	return (short)Maskbyte(1,3);
}
short PS3controller::SANKAKU(){
	return Maskbyte(1,4);
}
short PS3controller::MARU(){
	return Maskbyte(1,5);
}
short PS3controller::BATSU(){
	return (short)Maskbyte(1,6);
}
short PS3controller::SHIKAKU(){
	return (short)Maskbyte(1,7);
}
short PS3controller::ANALOG_RIGHT_X(){
	return (short)Data[2];
}
short PS3controller::ANALOG_RIGHT_Y(){
	return (short)Data[3];
}
short PS3controller::ANALOG_LEFT_X(){
	return (short)Data[4];
}
short PS3controller::ANALOG_LEFT_Y(){
	return (short)Data[5];
}

short PS3controller::L2(){
	return Data[6];
}
short PS3controller::R2(){
	return Data[7];
}
