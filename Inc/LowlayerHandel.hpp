/*
 * Robot.hpp
 *
 *  Created on: 2018/06/25
 *      Author: 裕汰
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include <encoder/RotaryEncoder.hpp>
#include"Motor/Motor.hpp"
#include "Aircylinder/Aircylinder.hpp"
#include "Servo/Servo.hpp"
#include "CAN/CAN.hpp"
#include "localization/localization.hpp"
#include "MotorSystem/MotorSystemClass.hpp"
#include "LCD/LCD.hpp"
#include "Sensor/Sensor.hpp"
#include "PS3/PS3class.hpp"
#include "Buzzer/Buzzer.h"
#include "tim.h"
//#define MOTERSYSTEM
#define KODOSERVO
/****************************************/
struct LowlayerHandelTypedef //低レイヤーハンドラをまとめた構造体 上位はこのハンドルを使ってアクセス
{
protected:


public:
	/*CAN communicate handle*/

	CanBus extcan_d, extcan_r,stdcan_d;

	/*************************/
	void EmagenceStop()//プログラムから緊急停止する関数
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
	}
	void PowerOn()//緊急停止を解除する関数
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
	}
	Aircylinder Air1,Air2,Air3,Air4,Air5,Air6,Air7,Air8;
#ifdef MOTERSYSTEM
	MotorSystem M1,M2,M3,M4,M5,M6,M7,M8;
#endif
#ifndef MOTERSYSTEM
	Motor M1,M2,M3,M4,M5,M6,M7,M8;
#endif
	Servo servo1,servo2,servo3,servo4,servo5,servo6,servo7,servo8;
	PS3controller PS3;
	localization loca;
	Encoder encoder1,encoder2,encoder3,encoder4;
	Sensor Ad1,Ad2,Ad3,Ad4,Ad5,Ad6;
	MicroSw Msw1,Msw2,Msw3,Msw4,Msw5,Msw6;
	LCD lcd;//LCD表示　絶対に制御周期の中で表示させないで
	Buzzer buzzer;//ブザー
	LowlayerHandelTypedef():extcan_d(CAN_ID_EXT,CAN_RTR_DATA),extcan_r(CAN_ID_EXT,CAN_RTR_REMOTE),stdcan_d(CAN_ID_STD,CAN_RTR_DATA)
	,M1(&extcan_d,1),M2(&extcan_d,2),M3(&extcan_d,3),M4(&extcan_d,4),
			M5(&extcan_d,5),M6(&extcan_d,6),M7(&extcan_d,7),M8(&extcan_d,8),Air1(&extcan_d,1),Air2(&extcan_d,2),Air3(&extcan_d,3)
	,Air4(&extcan_d,4),Air5(&extcan_d,5),Air6(&extcan_d,6),Air7(&extcan_d,7),Air8(&extcan_d,8),servo1(&extcan_d,1),servo2(&extcan_d,2)
	,servo3(&extcan_d,3),servo4(&extcan_d,4),servo5(&extcan_d,5),servo6(&extcan_d,6),servo7(&extcan_d,7),servo8(&extcan_d,8)
	,loca(&extcan_d,&extcan_r),encoder1(&extcan_r,1,1),encoder2(&extcan_r,2,1),encoder3(&extcan_r,3,1),encoder4(&extcan_r,4,1),PS3(&extcan_r)
	,Ad1(&extcan_r,1),Ad2(&extcan_r,2),Ad3(&extcan_r,3),Ad4(&extcan_r,4),Ad5(&extcan_r,5),Ad6(&extcan_r,6),Msw1(&extcan_d,0,1),Msw2(&extcan_d,1,1),Msw3(&extcan_d,2,1),
	Msw4(&extcan_d,3,1),Msw5(&extcan_d,4,1),Msw6(&extcan_d,5,1),buzzer(&htim3)
	{
		PowerOn();
	}

};



#endif /* ROBOT_HPP_ */
