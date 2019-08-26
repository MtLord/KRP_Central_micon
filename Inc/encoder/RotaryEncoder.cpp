/*
 * RotaryEncoder.cpp
 *
 *  Created on: 2018/12/22
 *      Author: �T��
 */

#include "encoder/RotaryEncoder.hpp"
#include "DefineOrder.h"

extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[12];

void Encoder::Sendreqest(unsigned long cmd)
{
	canbus->Send(GRT_ENCODER_COUNT<<ORDER_BIT_Pos|board_ID,0,0);
}

float Encoder::GetDistance(float d,float count)
{
	dist=countdata*d/count;
		return dist;
}

void Encoder::SetData()
{
	if(RXmsg.ExtId==(GRT_ENCODER_COUNT<<ORDER_BIT_Pos|board_ID))
	{
		for(int i=0;i<4;i++)
			{
				((unsigned char *)&countdata)[i]=RxFIFO_Data[i];
			}
	}
}
