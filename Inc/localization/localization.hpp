/*
 * Get_position.hpp
 *
 *  Created on: 2018/08/28
 *      Author: 裕汰
 */

#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_
#include "math.h"
#include "CAN/CAN.hpp"
class localization
{
	CanBus *canbus,*canbus_r;
	float diameter=0.041;
	unsigned long pulse=2048;
	float ShiftY=0.26;
	float ShiftX=0.26;
	float initX=0;
	float initY=0;
	unsigned char txdata[8];
	unsigned char txdata2[8];
	bool beginend1=false;
	bool beginend2=false;
	float currentX=0;
	float currentY=0;
	float currentyaw=0;
	unsigned long timcount1=0,timcount2=0;
public:
	 localization(CanBus *_canbus,CanBus *_canbus_r):canbus(_canbus),canbus_r(_canbus_r)
	{

	 }
	 void SendReqest();//send reqest localization
	 void Setloca();//dataset

	 void begin();
	 float GetX();

	 float GetY();

	 float GetYaw();
	void Setshitf_X(float x)//機体中心からのズレを記述
	{
		ShiftX=x;
	}
	void Setshift_y(float y){
		ShiftY=y;
	}

	void SetDiameter(float d)
	{
		 diameter=d;

	}
	void SetRotaryPulse(int P)
	{
		 pulse=P;
	}

};



#endif /* APPLICATION_LOCALIZATON_HPP_ */
