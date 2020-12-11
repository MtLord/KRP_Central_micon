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
class Application
{
private:

	short orderid=0;
	short nodeid=0;
	UART_HandleTypeDef *puart;
	unsigned char rx_buff[8]={0,};
	LowlayerHandelTypedef *plow;
	void TakeOrder();
	enum
	{
		MOTORE_SET_DUTY = 0x62,
		AIR_OPEN = 0x21,
		AIR_CLOSE = 0x22,
		Get_SENSOR = 0x31,
		GET_MICROSWITCH = 0x32,
		SETPPER_SET_PULSE = 0x51,
		GET_LOCA = 0x11,
		SET_INIT_POSE = 0x10,
		SET_ENCO_POSE = 0x12,
		SET_ENCO_PULSE = 0x13,
		GRT_ENCODER_COUNT = 0x14,
		SET_ENC_DIAMTER = 0x15,
		SET_ENC_DIRECTION = 0x16,
		GET_SWITCH = 0xA1,

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
	Application(LowlayerHandelTypedef *_plow):plow(_plow)
	{

	}
	int SetSerial();
	int SetRecieveData();
	int TaskShift();
};



#endif /* APPLICATION_HPP_ */