/*
 * SwitchModule.hpp
 *
 *  Created on: 2020/01/05
 *      Author: óTëø
 */

#ifndef SWITCH_SWITCHMODULE_HPP_
#define SWITCH_SWITCHMODULE_HPP_
#include "Libraries/CAN/CAN.hpp"
class SwitchModule
{
	CanBus *canbus;
	bool TXok=false;
	int tx_led=0;
	unsigned short data[6]={0,};
	unsigned char led_data=0;
public:

	SwitchModule(CanBus *_canbus):canbus(_canbus)
	{

	}
	void SetLedMode(int led1,int led2,int led3,int led4,int led5,int led6);//LEDÇÃì_ìîèÛë‘ÇïœçXÇ∑ÇÈ
	void SendReqest();//send request switch state
	void SetData();
	short GetAdData1();
	short GetAdData2();
	short GetToggleState(int num);
	short GetTactState(int num);
};



#endif /* SWITCH_SWITCHMODULE_HPP_ */
