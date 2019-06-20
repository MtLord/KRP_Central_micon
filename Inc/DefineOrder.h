/*
 * DefineOrder.h
 *
 *  Created on: 2019/05/04
 *      Author: —T‘¿
 */

#ifndef DEFINEORDER_H_
#define DEFINEORDER_H_

#define ORDER_BIT_Pos 6U//extid sift bit
#define ORDER_BIT_Pos_S 4U//stdid sift bit
#define NODE_ID_Pos 2U

enum{
	MOTORE_SET_DUTY=0x2,
	SERVO_SET_DUTY=0x42,
	SERVO_SET_FREAQENCY=0x40,
	AIR_OPEN=0x21,
	AIR_CLOSE=0x22,
	Get_SENSOR=0x31,
	GET_MICROSWITCH=0x32,
	LOCA_BEGIN=0x10,
	GET_LOCA=0x11,
	GRT_ENCODER_COUNT=0x14

};




#endif /* DEFINEORDER_H_ */
