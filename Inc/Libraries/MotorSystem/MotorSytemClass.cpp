/*
 * MotorSytemClass.cpp
 *
 *  Created on: 2018/09/27
 *      Author: —T‘¿
 */


#include "MotorSystemClass.hpp"
#include "MotorSystem_definetion.hpp"
#include "stdio.h"
#include "Libraries/DefineLED.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[6];
void MotorSystem::SetSendData(int cmd,unsigned char Len,float data)
{
	unsigned char msg[4];
	msg[0]=((unsigned char*)&data)[0];
	msg[1]=((unsigned char*)&data)[1];
	msg[2]=((unsigned char*)&data)[2];
	msg[3]=((unsigned char*)&data)[3];
	while(TXok==false)
	{
		if(Mcan->Send(cmd<<4|this->commuincationID,Len,msg)!=0)
		{

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

void MotorSystem::SetReceevieData(unsigned short *ID,unsigned char *DLC,float *data)
{

	*ID=RXmsg.StdId;
	*DLC=RXmsg.DLC;
	((unsigned char*)data)[0]=RxFIFO_Data[0];
	((unsigned char*)data)[1]=RxFIFO_Data[1];
	((unsigned char*)data)[2]=RxFIFO_Data[2];
	((unsigned char*)data)[3]=RxFIFO_Data[3];

}

float MotorSystem::SetReceevieData()
{
	float data;
	((unsigned char*)&data)[0]=RxFIFO_Data[0];
	((unsigned char*)&data)[1]=RxFIFO_Data[1];
	((unsigned char*)&data)[2]=RxFIFO_Data[2];
	((unsigned char*)&data)[3]=RxFIFO_Data[3];
	return data;
}
void MotorSystem::SetDuty(float d)
{
	this->SetSendData(SET_DUTY,4,d);
}

void MotorSystem::SetVelocity(float v)
{
	this->SetSendData(SET_VELOCITY,4,v);
}

void MotorSystem::SetTorque(float q)
{
	this->SetSendData(SET_TORQUE,4,q);

}

void MotorSystem::begin()
{
	bool BeginEnd=false;
	this->SetSendData(BEGIN,0,0);
	while(BeginEnd==false)
	{
		printf("NOW MOTOE%d INITIALIZING\n\r",this->commuincationID);
		if((RXmsg.StdId>>4)==0x44)
		{
			BeginEnd=true;
		}
	}
	 printf("INITIALIZING FINSH!\n\r");
}



void MotorSystem::SetVGAIN_K(float vk)
{
	this->SetSendData(SET_VGAIN_K,4,vk);
}

void MotorSystem::SetVGAIN_TI(float ti)
{
	this->SetSendData(SET_VGAIN_TI,4,ti);

}


void MotorSystem::SetVGAIN_TD(float td)
{
	this->SetSendData(SET_VGAIN_TD,4,td);

}

void MotorSystem::SetPPR(float p)
{
	this->SetSendData(SET_PPR,4,p);

}

void MotorSystem::Set_KT(float T)
{
	this->SetSendData(SET_KT,4,T);
}

void MotorSystem::SetCGAIN_K(float ck)
{
	this->SetSendData(SET_CGAIN_K,4,ck);

}

void MotorSystem::SetCGAIN_TI(float ti)
{
	this->SetSendData(SET_CGAIN_TI,4,ti);

}

void MotorSystem::SerCGAIN_TD(float td)
{
	this->SetSendData(SET_CGAIN_TD,4,td);

}

float MotorSystem::GetVelocity()
{

	this->SetSendData(GET_VELOCITY,4,0);
	do
	{


	}while((RXmsg.StdId)!=(GET_VELOCITY<<4|commuincationID));
	return this->SetReceevieData();
}

float MotorSystem::GetDuty()
{
	this->SetSendData(GET_DUTY,4,0);
		do
		{

		}while((RXmsg.StdId)!=(GET_DUTY<<4|commuincationID));
		return this->SetReceevieData();
}

float MotorSystem::GetCurrent()
{
	this->SetSendData(GET_CURRENT,4,0);
			do
			{


			}while((RXmsg.StdId)!=(GET_CURRENT<<4|commuincationID));
			return this->SetReceevieData();

}

float MotorSystem::GetTorque()
{
	this->SetSendData(GET_TORQUE,4,0);
				do
				{

				}while((RXmsg.StdId)!=(GET_TORQUE<<4|commuincationID));
				return this->SetReceevieData();

}

void MotorSystem::SetVcc(float c)
{
	this->SetSendData(SET_VCC,4,c);
}



