/*
 * Aircylinder.cpp
 *
 *  Created on: 2018/12/17
 *      Author: —T‘¿
 */

#include "Aircylinder/Aircylinder.hpp"

#include "DefineOrder.h"


void Aircylinder::open()
{
	canbus->Send(AIR_OPEN<<ORDER_BIT_Pos|nodeID<<NODE_ID_Pos,0,0);
}

void Aircylinder::close()
{
	canbus->Send(AIR_CLOSE<<ORDER_BIT_Pos|nodeID<<NODE_ID_Pos,0,0);
}

