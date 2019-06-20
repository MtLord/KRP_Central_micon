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
public:
	MicroSw(CanBus *_canbus):canbus(_canbus){

	}
	void SendRequest();
	void GetPush();
};

#endif /* SENSOR_SENSOR_HPP_ */
