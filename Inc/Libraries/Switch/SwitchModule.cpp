/*
 * SwitchModule.cpp
 *
 *  Created on: 2020/01/05
 *      Author: 裕汰
 */


#include "Libraries/Switch/SwitchModule.hpp"
#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"
extern CAN_RxHeaderTypeDef RXmsg;
extern unsigned char RxFIFO_Data[6];

void SwitchModule::SendReqest()
{
	while(TXok==false)
	{
		if(canbus->Send(GET_SWITCH<<ORDER_BIT_Pos,1,&led_data)!=0)
		{
			ERROR_LED;//送信エラーLED点滅
		}
		else
		{
			if(tx_led>18){
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

void SwitchModule::SetData()
{
	if(RXmsg.ExtId==(GET_SWITCH<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos))
	{
		data[0]=RxFIFO_Data[0];//togggle switch
		data[1]=RxFIFO_Data[1];//tactswitch
		((unsigned char *)&data[2])[0]=RxFIFO_Data[2];//2:AD1
		((unsigned char *)&data[2])[1]=RxFIFO_Data[3];
		((unsigned char *)&data[3])[0]=RxFIFO_Data[4];//3:AD2
		((unsigned char *)&data[3])[1]=RxFIFO_Data[5];
	}
}


void SwitchModule::SetLedMode(int led1,int led2,int led3,int led4,int led5,int led6)
{
	this->led_data|=led6<<5;
	this->led_data|=led5<<4;
	this->led_data|=led4<<3;
	this->led_data|=led3<<2;
	this->led_data|=led2<<1;
	this->led_data|=led1<<0;
}

short SwitchModule::GetToggleState(int num)
{
	switch(num)
	{
	case 1:
		return data[0]&1;
		break;
	case 2:
		return (data[0]>>1)&1;
		break;
	case 3:
		return (data[0]>>2)&1;
		break;
	case 4:
		return (data[0]>>3)&1;
		break;
	case 5:
		return (data[0]>>4)&1;
		break;
	case 6:
		return (data[0]>>5)&1;
		break;
	case 7:
		return (data[0]>>6)&1;
		break;
	default:
		return -1;
		break;
	}
}

short SwitchModule::GetTactState(int num)
{
	switch(num)
		{
		case 1:
			return data[1]&1;
			break;
		case 2:
			return (data[1]>>1)&1;
			break;
		case 3:
			return (data[1]>>2)&1;
			break;
		case 4:
			return (data[1]>>3)&1;
			break;
		default:
			return -1;
			break;
		}
}

short SwitchModule::GetAdData1()
{
	return data[2];
}

short SwitchModule::GetAdData2()
{
	return data[3];
}
