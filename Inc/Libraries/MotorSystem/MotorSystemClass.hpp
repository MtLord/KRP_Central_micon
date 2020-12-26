/*
 * MotorSystemClass.hpp
 *
 *  Created on: 2018/09/27
 *      Author: �T��
 */

#ifndef MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#define MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#include "Libraries/CAN/CAN.hpp"
class MotorSystem
{
private:
	unsigned short commuincationID;
	CanBus *Mcan;

	bool TXok=false;
	int tx_led=0;
	void SetVGAIN_K(float vk);//���x����̃Q�C��
		void SetVGAIN_TI(float ti);//���x����̐ϕ�����
		void SetVGAIN_TD(float td);//���x����̔�������
		void SetCGAIN_K(float ck);//�d������̃Q�C��
		void SetCGAIN_TI(float ti);//�d������̐ϕ�����
		void SerCGAIN_TD(float td);//�d������̔�������

		short SetSendData(int cmd,unsigned char Len,float data);
		void SetReceevieData(unsigned short *ID,unsigned char *DLC,float *data);
		float SetReceevieData();
public:
	MotorSystem(CanBus *canbus,unsigned short ID):commuincationID(ID),Mcan(canbus)
	{

	}




	void SetVelocity(float v);//rad/s
	void SetTorque(float q);//mNm
	void SetDuty(float d);//-100%~100%
	int begin();
	void Set_KT(float T);//�g���N�萔�̐ݒ�
	void SetVcc(float c);
	void SetPPR(float p);//�G���R�[�_�[�̃p���X���̐ݒ� ppR

	float GetVelocity();//���x�̎擾
	float GetTorque();//�g���N�̎擾
	float GetDuty();//�f���[�e�B�[�̎擾
	float GetCurrent();//�d���̎擾
	float GetState();//��Ԃ̎擾
};




#endif /* MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_ */
