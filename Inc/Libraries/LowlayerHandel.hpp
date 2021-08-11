/*
 * Robot.hpp
 *
 *  Created on: 2018/06/25
 *      Author: �T��
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include <Libraries/encoder/RotaryEncoder.hpp>
#include "Libraries/Motor/Motor.hpp"
#include "Libraries/Aircylinder/Aircylinder.hpp"
#include "Libraries/CAN/CAN.hpp"
#include "localization/localization.hpp"
#include "Libraries/MotorSystem/MotorSystemClass.hpp"

#include "Libraries/Sensor/Sensor.hpp"
#include "Libraries/PS3/PS3class.hpp"


#include "tim.h"
#include "Libraries/Steppre/SteppingMotor.hpp"
/*****switch profile****************/
/****************************************/
struct LowlayerHandelTypedef
{
protected:


public:
	/*CAN communicate handle*/

	CanBus extcan_d, extcan_r,stdcan_d;

	/*************************/

	Motor SM1,SM2,SM3,SM4,SM5,SM6,SM7,SM8,BR1,BR2,BR3,BR4;
	MotorSystem M1,M2,M3,M4,M5,M6,M7,M8;
	Aircylinder Air1,Air2,Air3,Air4,Air5,Air6,Air7,Air8;
	localization loca;
	Encoder encoder1,encoder2,encoder3,encoder4,encoder5,encoder6,encoder7,encoder8;
	Sensor Ad1,Ad2,Ad3,Ad4,Ad5,Ad6;
	MicroSw Msw1,Msw2,Msw3,Msw4,Msw5,Msw6,Msw7;
	SteppingMotor Stepper1,Stepper2,Stepper3;
	LowlayerHandelTypedef():extcan_d(CAN_ID_EXT,CAN_RTR_DATA),extcan_r(CAN_ID_EXT,CAN_RTR_REMOTE),stdcan_d(CAN_ID_STD,CAN_RTR_DATA)
	,SM1(&extcan_d,1,1),SM2(&extcan_d,2,1),SM3(&extcan_d,3,1),SM4(&extcan_d,4,1),SM5(&extcan_d,1,2),SM6(&extcan_d,2,2),SM7(&extcan_d,3,2),SM8(&extcan_d,4,2)
	,BR1(&extcan_d,17,1),BR2(&extcan_d,18,1),BR3(&extcan_d,17,2),BR4(&extcan_d,18,2)
	,M1(&stdcan_d,1),M2(&stdcan_d,2),M3(&stdcan_d,3),M4(&stdcan_d,4),M5(&stdcan_d,5),M6(&stdcan_d,6),M7(&stdcan_d,7),M8(&stdcan_d,8)
	,Air1(&extcan_d,1),Air2(&extcan_d,2),Air3(&extcan_d,3),Air4(&extcan_d,4),Air5(&extcan_d,5),Air6(&extcan_d,6),Air7(&extcan_d,7),Air8(&extcan_d,8)
	,loca(&extcan_d,&extcan_r)
	,encoder1(&extcan_r,0,1),encoder2(&extcan_r,1,1),encoder3(&extcan_r,2,1),encoder4(&extcan_r,3,1),encoder5(&extcan_r,4,2),encoder6(&extcan_r,5,2),encoder7(&extcan_r,6,2),encoder8(&extcan_r,7,2)
	,Ad1(&extcan_r,0),Ad2(&extcan_r,1),Ad3(&extcan_r,2),Ad4(&extcan_r,3),Ad5(&extcan_r,4),Ad6(&extcan_r,5)
	,Msw1(&extcan_d,0,1),Msw2(&extcan_d,1,1),Msw3(&extcan_d,2,1),Msw4(&extcan_d,3,1),Msw5(&extcan_d,4,1),Msw6(&extcan_d,5,1),Msw7(&extcan_d,6,1)
	,Stepper1(&extcan_d,1),Stepper2(&extcan_d,2),Stepper3(&extcan_d,3)
	{

	}

};



#endif /* ROBOT_HPP_ */
