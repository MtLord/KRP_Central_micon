/*
 * Buzzer.cpp
 *
 *  Created on: 2019/08/12
 *      Author: 裕汰
 */

#include "Buzzer.h"
#include "tim.h"

void Buzzer::SetFrequency(long freq)
{
	float freqency=freq;
		unsigned short counterperiod=0;
		unsigned short Prescaler=0;
		float ajustfreq=0;
		long sysclock=0;
			sysclock=HAL_RCC_GetPCLK1Freq();

		while(ajustfreq!=freqency)
		{
					Prescaler++;
				for(counterperiod=0;counterperiod<65535;counterperiod++)
				{
					ajustfreq=(float)sysclock/((float)Prescaler*((float)counterperiod+1));
					if(ajustfreq==freqency)
					{
						break;
					}
				}

		}
		htim->Instance->PSC=(unsigned short)Prescaler-1;    //プリスケーラ値セット
		htim->Instance->ARR=(unsigned short)counterperiod; //カウンターピリオド値セット

}

void Buzzer::Vibrate()
{
	    HAL_TIM_PWM_Start(htim,TIM_CHANNEL_1) ;
	    __HAL_TIM_SetCompare(htim,TIM_CHANNEL_1,map(50,0,100,0,htim2.Instance->ARR));
}

