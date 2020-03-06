/*
 * SteppingMotor.cpp
 *
 *  Created on: 2019/12/16
 *      Author: �T��
 */


#include "Libraries/Steppre/SteppingMotor.hpp"
#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"


void SteppingMotor::DivideData(short data)
{
	for(int i=0;i<1;i++)
		{
			tx_buff[i]=((unsigned char*)&data)[i];
		}
}



short SteppingMotor::SetPulse(short pulse)
{
	this->DivideData(pulse);
		while(TXok==false)
		{
			if(canbus->Send(SETPPER_SET_PULSE<<ORDER_BIT_Pos|this->node_id<<NODE_ID_Pos,4,tx_buff)!=0)
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


