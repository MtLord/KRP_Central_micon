/*
 * RotaryEncoder.cpp
 *
 *  Created on: 2018/12/22
 *      Author: —T‘¿
 */

#include "encoder/RotaryEncoder.hpp"
#include "DefineOrder.h"

extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[12];

void Encoder::Sendreqest(unsigned long cmd)
{

}

float Encoder::GetDistance(float d,float count)
{
	canbus->Send(GRT_ENCODER_COUNT<<ORDER_BIT_Pos|nodeID<<NODE_ID_Pos,0,0);
	while(RXmsg.ExtId!=(GRT_ENCODER_COUNT<<ORDER_BIT_Pos|nodeID<<NODE_ID_Pos))
	{
		HAL_Delay(1/1000);
	}
	for(int i=0;i<3;i++)
	{
		((unsigned char *)&countdata)[i]=RxFIFO_Data[i];
	}
	dist=countdata*d/count;
		return dist;
}
