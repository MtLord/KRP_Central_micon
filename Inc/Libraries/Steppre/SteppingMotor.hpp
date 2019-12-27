/*
 * SteppingMotor.hpp
 *
 *  Created on: 2019/12/16
 *      Author: —T‘¿
 */

#ifndef STEPPRE_STEPPINGMOTOR_HPP_
#define STEPPRE_STEPPINGMOTOR_HPP_
#include "Libraries/CAN/CAN.hpp"
class SteppingMotor
{
private:
	CanBus *canbus;
	int tx_led=0;
	int node_id;
	bool TXok=false;
	void DivideData(short data);
	unsigned char tx_buff[8]={0,};
public:
	SteppingMotor(CanBus *_canbus,int ID):canbus(_canbus),node_id(ID){

	}
	short SetPulse(short pulse);
};



#endif /* STEPPRE_STEPPINGMOTOR_HPP_ */
