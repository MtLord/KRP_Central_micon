/*
 * Get_position.hpp
 *
 *  Created on: 2018/08/28
 *      Author: �T��
 */

#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_
#include "math.h"
#include "Libraries/CAN/CAN.hpp"
class localization
{
	CanBus *canbus,*canbus_r;
	int tx_led=0;
	float diameter=0.048;
	unsigned short pulse=2048;
	float ShiftY=0.26;
	float ShiftX=0.26;
	float initX=0;
	float initY=0;
	bool beginend1=false;
	bool beginend2=false;
	float currentX=0;
	float currentY=0;
	float currentyaw=0;
	unsigned long timcount1=0,timcount2=0;
	bool TXok=false;
public:
	 localization(CanBus *_canbus,CanBus *_canbus_r):canbus(_canbus),canbus_r(_canbus_r)
	{

	 }
	 void SendReqest();//send reqest localization
	 void Setloca();//dataset

	 float GetX();
	 float GetY();
	 float GetYaw();

	 void PutLCD();
	void SetIntialPosition(float x,float y);
	void SetEncoderModef(float x_of_y,float y_of_x);//�G���R�[�_�̋@�̒��S����̃Y�����L�q
	void SetDiameter(float d);
	void SetEncPulse(unsigned short p);
};



#endif /* APPLICATION_LOCALIZATON_HPP_ */
