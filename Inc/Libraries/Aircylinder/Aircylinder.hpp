/*
 * Aircylinder.hpp
 *
 *  Created on: 2018/12/17
 *      Author: —T‘¿
 */

#ifndef AIRCYLINDER_AIRCYLINDER_HPP_
#define AIRCYLINDER_AIRCYLINDER_HPP_
#include "Libraries/CAN/CAN.hpp"

class Aircylinder
{
	CanBus *canbus;
	unsigned char nodeID;
	bool TXok=false;
	int tx_led=0;
public:
	 void open();
	 void close();
	Aircylinder(CanBus *can,unsigned char ID):canbus(can),nodeID(ID)
	{

	}
	void SetOrder(int order);
};



#endif /* AIRCYLINDER_AIRCYLINDER_HPP_ */
