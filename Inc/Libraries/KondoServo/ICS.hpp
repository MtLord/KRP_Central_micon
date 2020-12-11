/*
 * ICS.hpp
 *
 *  Created on: 2019/08/07
 *      Author: —T‘¿
 */

#ifndef ICS_HPP_
#define ICS_HPP_

#include "usart.h"
#include "DefineCommand.h"
#include "stm32f4xx_hal.h"

class ICS
{
	UART_HandleTypeDef *usart;
	int Synchronize(uint8_t *txBuff, size_t txLength, uint8_t *rxBuff, size_t rxLength);
	int degPos(float deg);
	int posDeg(int pos);
public:
	ICS(UART_HandleTypeDef *_usart):usart(_usart)
	{
	}
	int SetPosition(uint8_t id,unsigned short pos);
	int SetAngle(uint8_t id,float angle);
	int SetSpeed(uint8_t id,uint8_t spData);
	int SetStretch(uint8_t id,uint8_t stData);
};






#endif /* ICS_HPP_ */
