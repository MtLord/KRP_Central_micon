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
extern uint8_t con_data[8];

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
	 plow->PS3.SetconData();
	 cunt++;
 }

