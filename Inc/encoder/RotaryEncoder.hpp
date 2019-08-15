/*
 * RotaryEncoder.hpp
 *
 *  Created on: 2018/12/22
 *      Author: —T‘¿
 */

#ifndef ENCODER_ROTARYENCODER_HPP_
#define ENCODER_ROTARYENCODER_HPP_
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "CAN/CAN.hpp"

class Encoder
{
	CanBus *canbus;
	unsigned short nodeID;
	void Sendreqest(unsigned long cmd);
	long countdata=0;
	float dist=0;
public:
	Encoder(CanBus *_canbus,unsigned char ID):canbus(_canbus),nodeID(ID){

	}
	float GetDistance(float d,float count);//(ƒMƒA‚Ìƒsƒbƒ`‰~’¼Œa,ˆêŽü‚ ‚½‚è‚ÌƒJƒEƒ“ƒg—Ê)
	void SetData();
};

#endif /* ENCODER_ROTARYENCODER_HPP_ */
