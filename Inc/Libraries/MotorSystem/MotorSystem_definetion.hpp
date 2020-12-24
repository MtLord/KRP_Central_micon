/*
 * MotorSystem_definetion.hpp
 *
 *  Created on: 2018/09/27
 *      Author: �T��
 */

#ifndef MOTORSYSTEM_MOTORSYSTEM_DEFINETION_HPP_
#define MOTORSYSTEM_MOTORSYSTEM_DEFINETION_HPP_
enum
{
	 BEGIN=0x54,
	 SET_VELOCITY= 0x00,
	 SET_CGAIN_K= 0x4C,
	 SET_TORQUE= 0x01,
	 SET_DUTY= 0x02,
	 SET_VCC =0x45,
	 SET_PPR =0x46,
	 SET_KT= 0x47,//�g���N�萔
	 SET_VGAIN_K =0x48,
	 SET_VGAIN_TI =0x49,
	 SET_VGAIN_TD =0x4A,
	 SET_CGAIN_TI =0x4D,
	 SET_CGAIN_TD =0x4E,
	 GET_VELOCITY= 0x70,
	 GET_TORQUE= 0x71,
	 GET_DUTY= 0x72,
	 GET_CURRENT =0x73,
	 GET_STATE= 0x74,
	 GET_V_K =0x78,
	 GET_V_TI =0x79,
	 GET_V_TD =0x7A,
	 GET_C_K =0x7C,
	 GET_C_TI= 0x7D,
	 GET_C_TD= 0x7E
};






#endif /* MOTORSYSTEM_MOTORSYSTEM_DEFINETION_HPP_ */
