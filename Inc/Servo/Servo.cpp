/*
 * Servo.cpp
 *
 *  Created on: 2018/12/02
 *      Author: —T‘¿
 */

#include "Servo.hpp"

#include "DefineOrder.h"


void Servo::DivideData(float data)
{
	for(int i=0;i<3;i++)
	{
		tx_buff[i]=((unsigned char*)&data)[i];
	}
}

void Servo::SetDuty(float duty)
{
	this->DivideData(duty);
	canbus->Send(SERVO_SET_DUTY<<ORDER_BIT_Pos_S|node_id,4,tx_buff);
}

