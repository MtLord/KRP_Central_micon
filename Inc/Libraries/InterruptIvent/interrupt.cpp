/*
 * interrupt.c
 *
 *  Created on: 2018/09/23
 *      Author: 鬮ｯ�ｽｬ陟�髮｣�ｽｽ�ｽｱ�ｿｽ�ｽｽ�ｽｰ
 */

#include "stm32f4xx_hal.h"
#include "Libraries/InterruptIvent/TimerInterruptCallback.hpp"
#include "Libraries/LowlayerHandel.hpp"
#include "Libraries/DefineOrder.h"
extern LowlayerHandelTypedef *plow;
extern uint8_t con_data[8];

bool intflag=false;

 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 {
	 if(htim->Instance==TIM6)
	 {
		 intflag=true;
 	 }
 }


