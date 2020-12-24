/*
 * localization.cpp
 *
 *  Created on: 2018/09/23
 *      Author: �T��
 */



#include <Libraries/localization/localization.hpp>

#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[6];

 /****************localization*****************************************/

void localization::SendReqest()
{
while(TXok==false)
{
	if(canbus_r->Send(GET_LOCA<<ORDER_BIT_Pos,0,0)!=0)
	{
		ERROR_LED;
	}
	else
	{
		if(tx_led>25){
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

void localization::Setloca()
{
	if(RXmsg.ExtId==(GET_LOCA<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos))
	{
		((unsigned char *)&currentX)[0]=RxFIFO_Data[0];
		((unsigned char *)&currentX)[1]=RxFIFO_Data[1];
		((unsigned char *)&currentX)[2]=RxFIFO_Data[2];
		((unsigned char *)&currentX)[3]=RxFIFO_Data[3];

		((unsigned char *)&currentY)[0]=RxFIFO_Data[4];
		((unsigned char *)&currentY)[1]=RxFIFO_Data[5];
		((unsigned char *)&currentY)[2]=RxFIFO_Data[6];
		((unsigned char *)&currentY)[3]=RxFIFO_Data[7];
	}
	else if(RXmsg.ExtId==(GET_LOCA<<ORDER_BIT_Pos|0x2<<NODE_ID_Pos))
	{
		((unsigned char *)&currentyaw)[0]=RxFIFO_Data[0];
		((unsigned char *)&currentyaw)[1]=RxFIFO_Data[1];
		((unsigned char *)&currentyaw)[2]=RxFIFO_Data[2];
		((unsigned char *)&currentyaw)[3]=RxFIFO_Data[3];
	}
}



void localization::SetEncoderModef(float x_of_y,float y_of_x)
{
	unsigned char txdata[8];
	this->ShiftX=x_of_y;
	this->ShiftY=y_of_x;
	txdata[0]=((unsigned char *)&ShiftX)[0];
	txdata[1]=((unsigned char *)&ShiftX)[1];
	txdata[2]=((unsigned char *)&ShiftX)[2];
	txdata[3]=((unsigned char *)&ShiftX)[3];

	txdata[4]=((unsigned char *)&ShiftY)[0];
	txdata[5]=((unsigned char *)&ShiftY)[1];
	txdata[6]=((unsigned char *)&ShiftY)[2];
	txdata[7]=((unsigned char *)&ShiftY)[3];
	canbus->Send(SET_ENCO_POSE<<ORDER_BIT_Pos,8,txdata);
}

void localization::SetDiameter(float d)
{
	unsigned char txdata2[4];
	this->diameter=d;
	txdata2[0]=((unsigned char *)&diameter)[0];
	txdata2[1]=((unsigned char *)&diameter)[1];
	txdata2[2]=((unsigned char *)&diameter)[2];
	txdata2[3]=((unsigned char *)&diameter)[3];
	canbus->Send(SET_ENC_DIAMTER<<ORDER_BIT_Pos,4,txdata2);
}

void localization::SetEncPulse(unsigned short p)
{
	unsigned char txdata2[4];
	this->pulse=p;
	txdata2[0]=((unsigned char *)&pulse)[0];
	txdata2[1]=((unsigned char *)&pulse)[1];
	canbus->Send(SET_ENCO_PULSE<<ORDER_BIT_Pos,2,txdata2);
}

float localization::GetX()
{
	return currentX;
}

float localization::GetY()
{
	return currentY;
}

float localization::GetYaw()
{
	return currentyaw;
}
