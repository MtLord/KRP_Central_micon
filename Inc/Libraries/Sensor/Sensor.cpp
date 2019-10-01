/*
 * Sensor.cpp
 *
 *  Created on: 2019/05/19
 *      Author: —T‘¿
 */

#include "Sensor.hpp"
#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[8];
unsigned short Sensor::sensordata[12]={0,};
unsigned char MicroSw::Data[4]={0,};


void Sensor::SendRequest()
{
  while(TXok==false)
  {
	if(canbus->Send(Get_SENSOR<<ORDER_BIT_Pos, 0, 0)!=0)
	{
		ERROR_LED;
	}
	else
	{
		if(tx_led>20){
			TOGGLE_TX_LED;
			tx_led=0;
		}
		else{
			tx_led++;
		}
		TXok=true;
	}
  }
  TXok=false;
}

void Sensor::SetData()
{
	if(RXmsg.ExtId==(Get_SENSOR<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos))
	{
		((unsigned char*)&sensordata[0])[0]=RxFIFO_Data[0];
		((unsigned char*)&sensordata[0])[1]=RxFIFO_Data[1];
		((unsigned char*)&sensordata[1])[0]=RxFIFO_Data[2];
		((unsigned char*)&sensordata[1])[1]=RxFIFO_Data[3];
		((unsigned char*)&sensordata[2])[0]=RxFIFO_Data[4];
		((unsigned char*)&sensordata[2])[1]=RxFIFO_Data[5];
		((unsigned char*)&sensordata[3])[0]=RxFIFO_Data[6];
		((unsigned char*)&sensordata[3])[1]=RxFIFO_Data[7];
	}
	else if(RXmsg.ExtId==(Get_SENSOR<<ORDER_BIT_Pos|0x2<<NODE_ID_Pos))
	{
		((unsigned char*)&sensordata[4])[0]=RxFIFO_Data[0];
		((unsigned char*)&sensordata[4])[1]=RxFIFO_Data[1];
		((unsigned char*)&sensordata[5])[0]=RxFIFO_Data[2];
		((unsigned char*)&sensordata[6])[1]=RxFIFO_Data[3];
	}
}

unsigned short Sensor:: GetValue()
{
	return sensordata[num];
}

void MicroSw::SendRequest()
{
	while(TXok==false)
	{
	if(canbus->Send(GET_MICROSWITCH<<ORDER_BIT_Pos, 0, 0)!=0){
		ERROR_LED;
		TXok=false;
	}
	else
	{
		if(tx_led>25)
				{
					TOGGLE_TX_LED;
					tx_led=0;
				}
				else{
					tx_led++;
				}
		TXok=true;
	}
	}
	TXok=false;
}

void MicroSw::SetData()
{
	if(RXmsg.ExtId==(GET_MICROSWITCH<<ORDER_BIT_Pos|1))
	{
		Data[0]=RxFIFO_Data[0];
	}
	else if(RXmsg.ExtId==(GET_MICROSWITCH<<ORDER_BIT_Pos|2))
	{
		Data[1]=RxFIFO_Data[1];
	}
}

int MicroSw::GetPush()
{
	if(boardnum==1)
	{
		return  (Data[0]>>conenum)&1;
	}
	else if(boardnum==2)
	{
		return  (Data[1]>>conenum)&1;
	}
}
