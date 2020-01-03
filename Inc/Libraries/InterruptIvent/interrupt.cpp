/*
 * interrupt.c
 *
 *  Created on: 2018/09/23
 *      Author: 鬮ｯ�ｽｬ陟�髮｣�ｽｽ�ｽｱ�ｿｽ�ｽｽ�ｽｰ
 */



#include "stm32f4xx_hal.h"
#include "Libraries/InterruptIvent/TimerInterruptCallback.hpp"
#include "Libraries/LowlayerHandel.hpp"
#include "i2c.h"
#include "Libraries/DefineOrder.h"
extern LowlayerHandelTypedef *plow;

uint8_t con_data[8]={0,};
bool IntFlag=false;
int cunt=0;
 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 			{
	 	 	 	if(htim->Instance==TIM6)
	 	 	 		{
 					IntFlag=true;

 					}

 			}

 void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
 {
	 HAL_I2C_Master_Receive_IT(&hi2c2,CON_ADDRESEE,con_data,8);
	 cunt++;
 }

