/*
 * Sensor.hpp
 *
 *  Created on: 2019/05/19
 *      Author: —T‘¿
 */

#ifndef SENSOR_SENSOR_HPP_
#define SENSOR_SENSOR_HPP_
#include "CAN/CAN.hpp"
class Sensor
{
	CanBus *canbus;
	unsigned short sensordata[12]={0,};
	int num;
public:
	Sensor(CanBus *_canbus,int _num):canbus(_canbus),num(_num)
	{

	}
	void SendRequest();
	void SetData();
	unsigned short GetValue();

};

class MicroSw
{
	CanBus *canbus;
	static unsigned char Data[4];
	int comnum=0;
	int boardnum=1;
public:
	MicroSw(CanBus *_canbus,int num,int brnum):canbus(_canbus),comnum(num),boardnum(brnum)
	{

	}
	void SetData();
	void SendRequest();
	int GetPush();
};

#endif /* SENSOR_SENSOR_HPP_ */
