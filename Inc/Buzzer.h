/*
 * Buzzer.h
 *
 *  Created on: 2019/07/12
 *      Author: óTëø
 */

#ifndef BUZZER_H_
#define BUZZER_H_

void SetFrequency(long freq)
{
	float freqency=freq;
			unsigned short counterperiod=0;
			unsigned short Prescaler=0;
			float ajustfreq=0;
			long sysclock=0;
//			if(Mhandler==&htim1)
//			{
//				sysclock=HAL_RCC_GetPCLK2Freq(); //TIM1,TIM8ÇÃèÍçá
//			}
//			else
//			{
				sysclock=HAL_RCC_GetPCLK1Freq();
//			}
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
			htim2.Init.Prescaler=(unsigned short)Prescaler-1;
			htim2.Init.Period=(unsigned short)counterperiod;
}

long map(float x, long in_min, long in_max, long out_min, long out_max)
		{
			return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
		}



#endif /* BUZZER_H_ */
