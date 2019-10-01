/*
 * Motor.cpp
 *
 *  Created on: 2019/05/05
 *      Author: —T‘¿
 */
#include "Motor.hpp"
#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"

void Motor::DivideData(float data)
{
	for(int i=0;i<4;i++)
	{
		tx_buff[i]=((unsigned char*)&data)[i];
	}
}

void Motor::SetDuty(float duty)
{
	this->DivideData(duty);
	while(TXok==false)
	{
		if(canbus->Send(MOTORE_SET_DUTY<<ORDER_BIT_Pos|node_id,4,tx_buff)!=0)
		{
			TXok=false;
		}
		else
		{
			if(tx_led>15)
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









