/*
 * Motor.hpp
 *
 *  Created on: 2019/05/05
 *      Author: �T��
 */

#ifndef MOTOR_MOTOR_HPP_
#define MOTOR_MOTOR_HPP_
#include "Libraries/CAN/CAN.hpp"

class Motor
{
	CanBus *canbus;
	void DivideData(float data);
	unsigned char tx_buff[8]={0,};
	unsigned short node_id;
	unsigned short boardid;
	bool TXok=false;
	int tx_led=0;
public:
	Motor(CanBus *_canbus,unsigned short _node_id,unsigned short _boardid):canbus(_canbus),node_id(_node_id),
	boardid(_boardid)
	{

	}
	void SetDuty(float duty);
};



#endif /* MOTOR_MOTOR_HPP_ */
