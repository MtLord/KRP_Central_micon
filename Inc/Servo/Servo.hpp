/*
 * Servo.hpp
 *
 *  Created on: 2018/12/02
 *      Author: —T‘¿
 */

#ifndef SERVO_SERVO_HPP_
#define SERVO_SERVO_HPP_
#include "CAN/CAN.hpp"

class Servo
{
	CanBus *canbus;
	void DivideData(float data);
	unsigned char tx_buff[8]={0,};
	unsigned short node_id;
public:
	Servo(CanBus *_canbus,unsigned short _node_id):canbus(_canbus),node_id(_node_id)
	{
	}
	void SetDuty(float duty);
	void SetFreaqency(float fre);
};




#endif /* SERVO_SERVO_HPP_ */
