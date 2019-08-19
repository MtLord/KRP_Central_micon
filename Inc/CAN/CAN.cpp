/*
 * CAN.cpp
 *
 *  Created on: 2018/12/28
 *      Author: 裕汰
 */

#include "CAN.hpp"
#include "can.h"
#include "stdio.h"
#include "LowlayerHandel.hpp"
unsigned char RxFIFO_Data[8];
CAN_RxHeaderTypeDef RXmsg;
bool CanRxFlag=false;
extern LowlayerHandelTypedef *plow;

#define MASKID_L 0x0000
#define FILTERID_L 0x0000

#define TOGGLE_TX_LED HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_9);
#define TOGGLE_RX_LED  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_8);
#define SET_ERROR_LED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
#define RESET_ERRORLED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);

int rx_led=0;
void FilterConfig()
{
	CAN_FilterTypeDef  sFilterConfig;
	sFilterConfig.FilterIdHigh=0x0000; //エンコーダ関連のメッセージ以外を受け取らないようにフィルタ設定
	sFilterConfig.FilterIdLow=FILTERID_L;
	sFilterConfig.FilterMaskIdHigh=0x0000;
	sFilterConfig.FilterMaskIdLow=MASKID_L;
	sFilterConfig.FilterFIFOAssignment=CAN_FILTER_FIFO0;//受信フィルタをFIFO0に設定
	sFilterConfig.FilterBank=0; //フィルタバンク番号を設 0-13
	sFilterConfig.FilterScale=CAN_FILTERSCALE_32BIT; //フィルタスケールExtIdまで
	sFilterConfig.FilterMode=CAN_FILTERMODE_IDMASK; //マスクモード
	sFilterConfig.FilterActivation=ENABLE; //フィルタ有効
//	sFilterConfig.SlaveStartFilterBank=14;

	if(HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig)!=HAL_OK)
		{
			printf("filter config error!");
		}
	HAL_CAN_Start(&hcan1);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
 {
	   HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&RXmsg,RxFIFO_Data);
	   CanRxFlag=true;
	   plow->Ad1.SetData();
	   plow->Msw1.SetData();
	   plow->PS3.SetconData();
	   plow->loca.Setloca();
	   plow->encoder1.SetData();
	   if(rx_led>20)
	   {
		   TOGGLE_RX_LED;
		   rx_led=0;
	   }
	   else
	   {
		   rx_led++;
	   }

 }

short CanBus::Send(unsigned long ID,unsigned char DLC,unsigned char *data)
{
	Txmsg.DLC=DLC;
	Txmsg.ExtId=ID;
	Txmsg.StdId=ID;
	Txmsg.IDE=this->IDE;
	Txmsg.RTR=this->RTR;
	while(Txok==false)
	{
		if((hcan1.Instance->TSR>>26&0x1)==1)//TME0 is Empty
						{

							if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX0)!=HAL_OK)
							{
								error_flag=true;
								error_code=hcan1.Instance->ESR>>4&0b111;
								return -1;
							}
							else
							{
								Txok=true;
								error_flag=false;
							}

						}
		else if((hcan1.Instance->TSR>>27&0x1)==1)//TME1 is empty
						{

							if(HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX1)!=HAL_OK)
							{
								error_flag=true;
								error_code=hcan1.Instance->ESR>>4&0b111;
								return -1;
							}
							else
							{
								Txok=true;
								error_flag=false;
							}

						}
		else if((hcan1.Instance->TSR>>28&0x1)==1)//TME2 is empty
						{

							if(	HAL_CAN_AddTxMessage(&hcan1,&Txmsg,data,(uint32_t*)CAN_TX_MAILBOX2)!=HAL_OK)
							{
								error_flag=true;
								error_code=hcan1.Instance->ESR>>4&0b111;
								return -1;
							}
							else
							{
								Txok=true;
								error_flag=false;
							}

						}

						if(error_flag)
						{
							switch(error_code)
							{
							case 1:
								printf("staff error\n\r");
								break;
							case 2:
								printf("form error\n\r");
								break;
							case 3:
								printf("ACK error\n\r");
								break;
							case 4:
								printf("bit recessive error\n\r");
								break;
							case 5:
								printf("bit dominant error\n\r");
								break;
							case 6:
								printf("CRC error\n\r");
								break;
							}
							SET_ERROR_LED;
							Txok=true;
						}
						else if(Txok)
						{
							if(txled>5) //5回送信ごとにLチカ
							{
								TOGGLE_TX_LED;
								txled=0;
							}
							else
							{
								txled++;
							}
							RESET_ERRORLED;
							return 0;
						}
	}
	Txok=false;
}

