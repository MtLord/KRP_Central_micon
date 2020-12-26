/*
 * RotaryEncoder.hpp
 *
 *  Created on: 2018/12/22
 *      Author: �T��
 */

#ifndef ENCODER_ROTARYENCODER_HPP_
#define ENCODER_ROTARYENCODER_HPP_
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "Libraries/CAN/CAN.hpp"

class Encoder
{
	CanBus *canbus;
	unsigned short board_ID;
	int enco_num;

	float dist=0;
	bool TXok=false;
	int tx_led=0;
public:
	Encoder(CanBus *_canbus,int num,unsigned char ID):canbus(_canbus),board_ID(ID),enco_num(num)
	{

	}
	bool getok=false;
	static long countdata[8];
	void Sendreqest();
	float GetDistance(float d,float count);//(�M�A�̃s�b�`�~���a,���������̃J�E���g��)
	void SetData();
};

#endif /* ENCODER_ROTARYENCODER_HPP_ */
