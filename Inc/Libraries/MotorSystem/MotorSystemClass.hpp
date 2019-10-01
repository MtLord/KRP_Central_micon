/*
 * MotorSystemClass.hpp
 *
 *  Created on: 2018/09/27
 *      Author: 裕汰
 */

#ifndef MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#define MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#include "Libraries/CAN/CAN.hpp"
class MotorSystem
{
private:
	CanBus *Mcan;
	unsigned short commuincationID;
	bool TXok=false;
	int tx_led=0;
	void SetVGAIN_K(float vk);//速度制御のゲイン
		void SetVGAIN_TI(float ti);//速度制御の積分時間
		void SetVGAIN_TD(float td);//速度制御の微分時間
		void SetCGAIN_K(float ck);//電流制御のゲイン
		void SetCGAIN_TI(float ti);//電流制御の積分時間
		void SerCGAIN_TD(float td);//電流制御の微分時間

		void SetSendData(int cmd,unsigned char Len,float data);
		void SetReceevieData(unsigned short *ID,unsigned char *DLC,float *data);
		float SetReceevieData();
public:
	MotorSystem(CanBus *canbus,unsigned short ID):commuincationID(ID),Mcan(canbus)
	{

	}




	void SetVelocity(float v);//rad/s
	void SetTorque(float q);//mNm
	void SetDuty(float d);//-100%~100%
	void begin();
	void Set_KT(float T);//トルク定数の設定
	void SetVcc(float c);
	void SetPPR(float p);//エンコーダーのパルス数の設定 ppR

	float GetVelocity();//速度の取得
	float GetTorque();//トルクの取得
	float GetDuty();//デューティーの取得
	float GetCurrent();//電流の取得
	float GetState();//状態の取得
};




#endif /* MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_ */
