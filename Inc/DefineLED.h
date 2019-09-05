/*
 * DefineLED.h
 *
 *  Created on: 2019/08/22
 *      Author: —T‘¿
 */

#ifndef DEFINELED_H_
#define DEFINELED_H_

#define TOGGLE_TX_LED HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_9)
#define TOGGLE_RX_LED HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_8)
#define ERROR_LED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET)
#define RESET_ERROR_LED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET)


#endif /* DEFINELED_H_ */
