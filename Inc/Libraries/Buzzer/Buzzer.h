/*
 * Buzzer.h
 *
 *  Created on: 2019/07/12
 *      Author: —T‘¿
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "stm32f4xx_hal.h"

class Buzzer
{
	TIM_HandleTypeDef *htim;
	long map(float x, long in_min, long in_max, long out_min, long out_max)
			{
				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}
public:
	Buzzer(TIM_HandleTypeDef *_htim):htim(_htim)
	{

	}
	void SetFrequency(long freq);
	void Vibrate();
};


#endif /* BUZZER_H_ */
