/*
 * LCD.h
 *
 *  Created on: 2019/06/10
 *      Author: 裕汰
 */
#include "stm32f4xx_hal.h"
#ifndef LCD_H_
#define LCD_H_

#define CMD 	0
#define DAT 	1
#define ON 	1
#define OFF 	0
#define IN		1
#define OUT 	0
#define line2 0xC0
#define line1 0x80
// LCD Control(ハードウェア依存部)
#define E_PORT		GPIOC
#define E_PIN			(1<<0)
#define RS_PORT	GPIOC
#define RS_PIN		(1<<1)

class LCD
{
private:
	void LCD_RW(char act);
	void LCD_E(char act);
	void LCD_RS(char act);
	void LCD_OUT(int dat);
	void lcd_write8(char reg, char dat);
	void lcd_write(char reg, char dat);
	void LcdPutc(char c);
public:
	void LcdCls();
	void LcdDisplayMode(char disp, char cursor, char blink);
	void LcdInit();
	void LcdPuts(char *str);
	void LcdXy(char x, char y);
};


//void LcdPuts2(char *str)
//{
//	lcd_write(CMD,0xC0);
//	HAL_Delay(10);
//	while(*str)
//		{
//			LcdPutc(*str);
//			str++;
//		}
//}








#endif /* LCD_H_ */
