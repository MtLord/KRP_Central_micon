/*
 * localization.cpp
 *
 *  Created on: 2018/09/23
 *      Author: —T‘¿
 */



#include <localization/localization.hpp>
#include "DefineOrder.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[6];

 /****************localization*****************************************/

void localization::SendReqest()
{
	if(canbus_r->Send(GET_LOCA<<ORDER_BIT_Pos,0,0)!=0)
	{
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
	}
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

void localization::begin()
{
	txdata[0]=((unsigned char *)&ShiftX)[0];
	txdata[1]=((unsigned char *)&ShiftX)[1];
	txdata[2]=((unsigned char *)&ShiftX)[2];
	txdata[3]=((unsigned char *)&ShiftX)[3];

	txdata[4]=((unsigned char *)&ShiftY)[0];
	txdata[5]=((unsigned char *)&ShiftY)[1];
	txdata[6]=((unsigned char *)&ShiftY)[2];
	txdata[7]=((unsigned char *)&ShiftY)[3];
	canbus->Send(LOCA_BEGIN<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos,8,txdata);
	while(RXmsg.ExtId!=(LOCA_BEGIN<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos))
	{
		if(timcount1>0x8000000)
		{
			beginend1=false;
			break;
		}
		else
		{
			beginend1=true;
		}
		this->timcount1++;
	}

	txdata2[0]=((unsigned char *)&diameter)[0];
	txdata2[1]=((unsigned char *)&diameter)[1];
	txdata2[2]=((unsigned char *)&diameter)[2];
	txdata2[3]=((unsigned char *)&diameter)[3];
	txdata2[4]=((unsigned char *)&pulse)[0];
	txdata2[5]=((unsigned char *)&pulse)[1];
	txdata2[6]=((unsigned char *)&pulse)[2];
	txdata2[7]=((unsigned char *)&pulse)[3];
	canbus->Send(LOCA_BEGIN<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos,8,txdata2);
	while(RXmsg.ExtId!=(LOCA_BEGIN<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos))
	{
		if(timcount2>0x8000000)
		{
			beginend2=false;
			break;
		}
		else
		{
			beginend2=true;
		}
		this->timcount2++;
	}

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
