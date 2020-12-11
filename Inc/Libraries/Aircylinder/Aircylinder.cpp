/*
 * Aircylinder.cpp
 *
 *  Created on: 2018/12/17
 *      Author: —T‘¿
 */

#include "Libraries/Aircylinder/Aircylinder.hpp"

#include "Libraries/DefineOrder.h"
#include "Libraries/DefineLED.h"

void Aircylinder::open()
{
	this->SetOrder(AIR_OPEN);
}

void Aircylinder::close()
{

	this->SetOrder(AIR_CLOSE);
}

void Aircylinder::SetOrder(int order)
{
  while(TXok==false)
  {
	if(canbus->Send(order<<ORDER_BIT_Pos|nodeID<<NODE_ID_Pos,0,0)!=0)
	{

	}
	else
	{
		TOGGLE_TX_LED;
		TXok=true;
	}
  }
  TXok=false;
}
