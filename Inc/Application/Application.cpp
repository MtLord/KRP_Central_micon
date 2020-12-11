/*
 * Application.cpp
 *
 *  Created on: 2020/12/11
 *      Author: yutakamiyama
 */
#include "Application.hpp"
#include "Libraries/DefineOrder.h"
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

}


void Application::TakeOrder()
{
	orderid=(rx_buff[0]>>4)&&0xF;
	nodeid=(rx_buff[0])&&0xF;
}

int Application::SetSerial()
{
	HAL_UART_Receive_IT(puart, rx_buff, 5);
	TakeOrder();

	return 0;
}

int Application::TaskShift()
{
	switch(orderid)
	{
	case MOTORE_SET_DUTY://モータ基板の命令

		break;
	}
}

