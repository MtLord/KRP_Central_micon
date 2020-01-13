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
	bool TXok=false;
public:
	 localization(CanBus *_canbus,CanBus *_canbus_r):canbus(_canbus),canbus_r(_canbus_r)
	{

	 }
	 void SendReqest();//send reqest localization
	 void Setloca();//dataset

	 void begin();//���Ȉʒu���W�Đݒ�
	 float GetX();
	 float GetY();
	 float GetYaw();

	 void PutLCD();
	 void SetIntialPoint(float x,float y);
	void Setshitf_X(float x)//�G���R�[�_�̋@�̒��S����̃Y�����L�q
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
