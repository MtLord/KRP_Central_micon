/*
 * Application.hpp
 *
 *  Created on: 2020/12/11
 *      Author: yutakamiyama
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_
#include "usart.h"
#include "Libraries/LowlayerHandel.hpp"
#include <queue>
using namespace std;
class Application
{
private:

	short orderid=0;
	short nodeid=0;
	short motorstate=0;
	unsigned char rx_buff[6]={0,};
	unsigned char txbuff[8]={0,};
	LowlayerHandelTypedef *plow;
	void TakeOrder();
	void SetSendOrder(uint8_t orderid,uint8_t ac_id);
	queue<unsigned char> orderbuff;//命令のキュー
	queue<unsigned char> actubuff;
	queue<float> rxdata;//受信値のキュー
	int SendSensor(unsigned short *buff,short ac_id,int start,int end);
	int SendMswitch(unsigned char buff,short board_id);
	int SendLoca(float data,short nodeid);
	int SendCount(short data1,short data2,short nodeid);
	int MotorSystemBegin(short nodeid);
	/*debug variable*/
	int motorsflag=0;
	int motorsflag2=0;
	int intflag=0;
	float tempduty=0;
	/*************************/

	enum
	{
		MOTORE_SET_DUTY = 0x62,
		AIR_OPEN = 0x21,
		AIR_CLOSE = 0x22,
		Get_SENSOR = 0x31,
		GET_MICROSWITCH = 0x32,
		SETPPER_SET_PULSE = 0x51,
		GET_LOCA = 0x11,
		SET_ENCO_POSE = 0x12,
		SET_ENCO_PULSE = 0x13,
		GRT_ENCODER_COUNT = 0x14,
		SET_ENC_DIAMTER = 0x15,

		BEGIN = 0x44,
		SET_VELOCITY = 0x00,
		SET_CGAIN_K = 0x4C,
		SET_TORQUE = 0x01,
		SET_DUTY = 0x02,
		SET_VCC = 0x45,
		SET_PPR = 0x46,
		SET_KT = 0x47,
		SET_VGAIN_K = 0x48,
		SET_VGAIN_TI = 0x49,
		SET_VGAIN_TD = 0x4A,
		SET_CGAIN_TI = 0x4D,
		SET_CGAIN_TD = 0x4E,
		GET_VELOCITY = 0x70,
		GET_TORQUE = 0x71,
		GET_DUTY = 0x72,
		GET_CURRENT = 0x73,
		GET_STATE = 0x74,
		GET_V_K = 0x78,
		GET_V_TI = 0x79,
		GET_V_TD = 0x7A,
		GET_C_K = 0x7C,
		GET_C_TI = 0x7D,
		GET_C_TD = 0x7E
	};
public:
	int odercount=0;
	Application(LowlayerHandelTypedef *_plow):plow(_plow)
	{
		HAL_UART_Receive_IT(&huart2, rx_buff, 6);
	}
	int SetSerial();


	int TaskShift();
};



#endif /* APPLICATION_HPP_ */
