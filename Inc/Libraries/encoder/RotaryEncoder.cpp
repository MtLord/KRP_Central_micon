/*
 * RotaryEncoder.cpp
 *
 *  Created on: 2018/12/22
 *      Author: �T��
 */

#include "Libraries/encoder/RotaryEncoder.hpp"
#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[12];
short Encoder::countdata[8] = {
	0,
};

void Encoder::Sendreqest()
{
	while (TXok == false)
	{
		if (canbus->Send(GRT_ENCODER_COUNT << ORDER_BIT_Pos | board_ID, 0, 0) != 0)
		{
		}
		else
		{
			if (tx_led > 30)
			{
				TOGGLE_TX_LED;
				tx_led = 0;
			}
			else
			{
				tx_led++;
			}
			TXok = true;
		}
	}
	TXok = false;
}

float Encoder::GetDistance(float d, float count)
{
	dist = countdata[enco_num] * d / count;
	return dist;
}

void Encoder::SetData()
{
	if (RXmsg.ExtId == (GRT_ENCODER_COUNT << ORDER_BIT_Pos | 1))
	{

		((unsigned char *)&countdata[0])[0] = RxFIFO_Data[0];
		((unsigned char *)&countdata[0])[1] = RxFIFO_Data[1];
		((unsigned char *)&countdata[1])[0] = RxFIFO_Data[2];
		((unsigned char *)&countdata[1])[1] = RxFIFO_Data[3];
		((unsigned char *)&countdata[2])[0] = RxFIFO_Data[4];
		((unsigned char *)&countdata[2])[1] = RxFIFO_Data[5];
		((unsigned char *)&countdata[3])[0] = RxFIFO_Data[6];
		((unsigned char *)&countdata[3])[1] = RxFIFO_Data[7];
	}
	else if (RXmsg.ExtId == (GRT_ENCODER_COUNT << ORDER_BIT_Pos | 2))
	{
		((unsigned char *)&countdata[4])[0] = RxFIFO_Data[0];
		((unsigned char *)&countdata[4])[1] = RxFIFO_Data[1];
		((unsigned char *)&countdata[5])[0] = RxFIFO_Data[2];
		((unsigned char *)&countdata[5])[1] = RxFIFO_Data[3];
		((unsigned char *)&countdata[6])[0] = RxFIFO_Data[4];
		((unsigned char *)&countdata[6])[1] = RxFIFO_Data[5];
		((unsigned char *)&countdata[7])[0] = RxFIFO_Data[6];
		((unsigned char *)&countdata[7])[1] = RxFIFO_Data[7];
	}
}
