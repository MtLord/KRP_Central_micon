/*
 * PS3class.cpp
 *
 *  Created on: 2018/08/20
 *      Author: —T‘¿
 */
#include "PS3class.hpp"


extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[6];



 void PS3controller::SetconData()
 {
 	if(RXmsg.ExtId==(0x75))
 	{
 		for(int i=0;i<6;i++)
 		{
 			Data[i]=RxFIFO_Data[i];
 		}
 	}
 }

 void PS3controller::SendRequest()
 {
	 canbus->Send((0x74),0,0);
 	if(canbus->Send((0x74),0,0)==-1){

 	}

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
short PS3controller::L2(){
	return (short)Maskbyte(1,0);
}
short PS3controller::R2(){
	return (short)Maskbyte(1,1);
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

void PS3controller::begin()
{
	canbus->Send(begincmd,0,0);
	while(RXmsg.ExtId!=0x71)
		{
			if(timecount>0x9000000)
			{
				beginend=false;
				break;
			}
			else
			{
				beginend=true;
			}
			timecount++;
		}
		if(beginend)
		{

		}
		else
		{

		}

}

