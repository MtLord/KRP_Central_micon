/*
 * Sensor.hpp
 *
 *  Created on: 2019/05/19
 *      Author: �T��
 */

#ifndef SENSOR_SENSOR_HPP_
#define SENSOR_SENSOR_HPP_
#include "CAN/CAN.hpp"
class Sensor
{
	CanBus *canbus;
	int tx_led=0;
	int num;
public:
	Sensor(CanBus *_canbus,int _num):canbus(_canbus),num(_num)
	{

	}
	void SendRequest();
	void SetData();
	static unsigned short sensordata[12];
	unsigned short GetValue();

};

class MicroSw
{
	CanBus *canbus;

	int conenum=0;
	int boardnum=1;
	int tx_led=0;
public:
	MicroSw(CanBus *_canbus,int _conenum,int brnum):canbus(_canbus),conenum(_conenum),boardnum(brnum)//(CAN handle,connection number,board number)
	{

	}
	static unsigned char Data[4];
	void SetData();
	void SendRequest();
	int GetPush();
};

#endif /* SENSOR_SENSOR_HPP_ */
