/*
 * interrupt.c
 *
 *  Created on: 2018/09/23
 *      Author: 鬮ｯ�ｽｬ陟�髮｣�ｽｽ�ｽｱ�ｿｽ�ｽｽ�ｽｰ
 */



#include "stm32f4xx_hal.h"
#include "InterruptIvent/TimerInterruptCallback.hpp"
#include "LowlayerHandel.hpp"
extern LowlayerHandelTypedef *plow;
bool IntFlag=false;
int warikan=0;
 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 			{
	 	 	 	if(htim->Instance==TIM6)
	 	 	 		{
 					IntFlag=true;

 					}

 			}



