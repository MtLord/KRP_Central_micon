/*
 * Servo.cpp
 *
 *  Created on: 2018/12/02
 *      Author: —T‘¿
 */

#include "Servo.hpp"

#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"

void Servo::DivideData(float data)
{
	for(int i=0;i<4;i++)
	{
		tx_buff[i]=((unsigned char*)&data)[i];
	}
}

void Servo::SetDuty(float duty)
{
	this->DivideData(duty);
  while(TXok==false)
  {
	if(canbus->Send(SERVO_SET_DUTY<<ORDER_BIT_Pos|node_id,4,tx_buff)!=0)
	{

	}
	else
	{

		TOGGLE_TX_LED;
		TXok=true;
	}
  }
  TXok=false;
}

//00000000000000|00000110|00000000
