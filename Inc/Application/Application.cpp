/*
 * Application.cpp
 *
 *  Created on: 2020/12/11
 *      Author: yutakamiyama
 */
#include "Application.hpp"
#include "Libraries/DefineOrder.h"
#include "usart.h"
#define STB 0x9E
#define ENB 0xFF

extern Application *App;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	App->SetSerial();//pcからの命令のセット
}


void Application::TakeOrder()
{
	orderbuff.push(rx_buff[0]);
	actubuff.push(rx_buff[1]);
}

int Application::SetSerial()
{
	intflag++;
	float temp_data=0;
	HAL_UART_Receive_IT(&huart2, rx_buff, 6);
	TakeOrder();
	((unsigned char *)&temp_data)[0]=rx_buff[2];
	((unsigned char *)&temp_data)[1]=rx_buff[3];
	((unsigned char *)&temp_data)[2]=rx_buff[4];
	((unsigned char *)&temp_data)[3]=rx_buff[5];
	rxdata.push(temp_data);
	return 0;
}

void Application::SetSendOrder(uint8_t orderid,uint8_t ac_id)
{
	txbuff[0]=STB;
	txbuff[1]=orderid;
	txbuff[2]=ac_id;
	txbuff[7]=ENB;
}

int Application::SendSensor(unsigned short *buff,short ac_id,int start,int end)
{
	SetSendOrder(Get_SENSOR,ac_id);//送信命令のセット
	txbuff[3]=((unsigned char*)&buff[start])[0];
	txbuff[4]=((unsigned char*)&buff[start])[1];
	txbuff[5]=((unsigned char*)&buff[end])[0];
	txbuff[6]=((unsigned char*)&buff[end])[1];

	HAL_UART_Transmit(&huart2,txbuff,8,5);
	return 0;
}

int Application::SendLoca(float data,short nodeid)
{
	SetSendOrder(GET_LOCA,nodeid);
	txbuff[3]=((unsigned char*)&data)[0];
	txbuff[4]=((unsigned char*)&data)[1];
	txbuff[5]=((unsigned char*)&data)[2];
	txbuff[6]=((unsigned char*)&data)[3];
	HAL_UART_Transmit(&huart2,txbuff,8,5);
	return 0;
}


int Application::SendMswitch(unsigned char buff,short board_id)
{
	SetSendOrder(GET_MICROSWITCH,board_id);
	txbuff[3]=buff;
	HAL_UART_Transmit(&huart2,txbuff,8,5);
	return 0;
}
int Application::SendCount(short data1,short data2,short nodeid)
{
	SetSendOrder(GRT_ENCODER_COUNT,nodeid);
	txbuff[3]=((unsigned char*)&data1)[0];
	txbuff[4]=((unsigned char*)&data1)[1];
	txbuff[5]=((unsigned char*)&data2)[0];
	txbuff[6]=((unsigned char*)&data2)[1];
	HAL_UART_Transmit(&huart2,txbuff,8,5);
	return 0;
}

int Application::MotorSystemBegin(short nodeid)
{
	if(motorstate!=0){
		SetSendOrder(BEGIN,-1);
	}
	else{
		SetSendOrder(BEGIN,nodeid);
	}
	HAL_UART_Transmit(&huart2,txbuff,8,5);
	return 0;
}

int Application::TaskShift()
{
	if(orderbuff.empty()==false)//命令バッファが空じゃなかったら
	{
		switch((int)orderbuff.front())
		{
			case MOTORE_SET_DUTY://モータ基板の命令
				switch((int)actubuff.front())
				{
					case 1:
						motorsflag++;
						plow->SM1.SetDuty(rxdata.front());
						break;
					case 2:
						plow->SM2.SetDuty(rxdata.front());
						break;
					case 3:
						plow->SM3.SetDuty(rxdata.front());
						break;
					case 4:
						plow->SM4.SetDuty(rxdata.front());
						break;
					case 5:
						plow->SM5.SetDuty(rxdata.front());
						break;
					case 6:
						plow->SM6.SetDuty(rxdata.front());
						break;
					case 7:
						plow->SM7.SetDuty(rxdata.front());
						break;
					case 8:
						plow->SM8.SetDuty(rxdata.front());
						break;
					case 17:
						motorsflag2++;
						plow->BR1.SetDuty(rxdata.front());
						break;
					case 18:
						plow->BR2.SetDuty(rxdata.front());
						break;
				}
				break;
			case AIR_OPEN:
				switch(actubuff.front())
				{
					case 1:
						plow->Air1.open();
						break;
					case 2:
						plow->Air2.open();
						break;
					case 3:
						plow->Air3.open();
						break;
					case 4:
						plow->Air4.open();
						break;
					case 5:
						plow->Air5.open();
						break;
					case 6:
						plow->Air6.open();
						break;
					case 7:
						plow->Air7.open();
						break;
					case 8:
						plow->Air8.open();
						break;
				}
				break;
			case AIR_CLOSE:
				switch(actubuff.front())
				{
					case 1:
						plow->Air1.close();
						break;
					case 2:
						plow->Air2.close();
						break;
					case 3:
						plow->Air3.close();
						break;
					case 4:
						plow->Air4.close();
						break;
					case 5:
						plow->Air5.close();
						break;
					case 6:
						plow->Air6.close();
						break;
					case 7:
						plow->Air7.close();
						break;
					case 8:
						plow->Air8.close();
						break;

				}
				break;
			case Get_SENSOR:
				switch(actubuff.front())
				{
					case 0x1:
						plow->Ad1.SendRequest();
						while(plow->Ad1.getok==false)//受信完了まで待つ
						{

						}
						SendSensor(plow->Ad1.sensordata,1,0,1);
					case 0x2:
						SendSensor(plow->Ad1.sensordata,2,2,3);
					case 0x3:
						SendSensor(plow->Ad1.sensordata,3,4,5);
						plow->Ad1.getok=false;
						break;
				}
				break;
			case GET_MICROSWITCH:
				switch(actubuff.front())
				{
					case 1://board1
						plow->Msw1.SendRequest();
						while(plow->Msw1.getok==false)//受信完了まで待つ
						{

						}
						SendMswitch(plow->Msw1.Data[0],1);
						plow->Msw1.getok=false;
						break;
					case 2:
						SendMswitch(plow->Msw1.Data[1],2);
						break;
				}
				break;
			case GET_LOCA:
				switch(actubuff.front())
				{
					case 1:
						plow->loca.SendReqest();
						while(plow->loca.getok==false)//受信完了まで待つ
						{

						}
						SendLoca(plow->loca.GetX(),1);
						break;
					case 2:
						SendLoca(plow->loca.GetY(),2);
						break;
					case 3:
						SendLoca(plow->loca.GetYaw(),3);
						plow->loca.getok=false;
						break;
				}



				break;
			case GRT_ENCODER_COUNT:
				switch(actubuff.front())
				{
					case 1:
						plow->encoder1.Sendreqest();
						while(plow->encoder1.getok==false)
						{

						}
						SendCount(plow->encoder1.countdata[0],plow->encoder1.countdata[1],1);
						break;
					case 2:
						SendCount(plow->encoder1.countdata[2],plow->encoder1.countdata[3],2);
						plow->encoder1.getok=false;
						break;
				}
				break;
			case BEGIN:
				switch(actubuff.front())
				{
					case 1:
						motorstate=plow->M1.begin();
						MotorSystemBegin(1);
						break;
					case 2:
						motorstate=plow->M2.begin();
						MotorSystemBegin(2);
						break;
					case 3:
						motorstate=plow->M3.begin();
						MotorSystemBegin(3);
						break;
					case 4:
						motorstate=plow->M4.begin();
						MotorSystemBegin(4);
						break;
					case 5:
						motorstate=plow->M5.begin();
						MotorSystemBegin(5);
						break;
					case 6:
						motorstate=plow->M6.begin();
						MotorSystemBegin(6);
						break;
					case 7:
						motorstate=plow->M7.begin();
						MotorSystemBegin(7);
						break;
					case 8:
						motorstate=plow->M8.begin();
						MotorSystemBegin(8);
						break;
				}
				break;
			case SET_VELOCITY:
				switch(actubuff.front())
				{
					case 1:
						plow->M1.SetVelocity(rxdata.front());
						break;
					case 2:
						plow->M2.SetVelocity(rxdata.front());
						break;
					case 3:
						plow->M3.SetVelocity(rxdata.front());
						break;
					case 4:
						plow->M4.SetVelocity(rxdata.front());
						break;
					case 5:
						plow->M5.SetVelocity(rxdata.front());
						break;
					case 6:
						plow->M6.SetVelocity(rxdata.front());
						break;
					case 7:
						plow->M7.SetVelocity(rxdata.front());
						break;
					case 8:
						plow->M8.SetVelocity(rxdata.front());
						break;
				}
				break;
			case SET_DUTY:
				switch(actubuff.front())
				{
					case 1:
						tempduty=rxdata.front();
						plow->M1.SetDuty(rxdata.front());
						break;
					case 2:
						plow->M2.SetDuty(rxdata.front());
						break;
					case 3:
						plow->M3.SetDuty(rxdata.front());
						break;
					case 4:
						plow->M4.SetDuty(rxdata.front());
						break;
					case 5:
						plow->M5.SetDuty(rxdata.front());
						break;
					case 6:
						plow->M6.SetDuty(rxdata.front());
						break;
					case 7:
						plow->M7.SetDuty(rxdata.front());
						break;
					case 8:
						plow->M8.SetDuty(rxdata.front());
						break;

				}
				break;
			default:
				break;

		}
		//先頭バッファの削除
		orderbuff.pop();
		actubuff.pop();
		rxdata.pop();
	}
	return 0;
}

