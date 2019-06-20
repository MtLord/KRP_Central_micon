/*
 * Sensor.cpp
 *
 *  Created on: 2019/05/19
 *      Author: —T‘¿
 */

#include "Sensor/Sensor.hpp"
#include "DefineOrder.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[8];
void Sensor::SendRequest()
{
	canbus->Send(Get_SENSOR<<ORDER_BIT_Pos, 0, 0);
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
