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

// LCD Control(ハードウェア依存部)
#define E_PORT		GPIOC
#define E_PIN			(1<<0)
#define RS_PORT	GPIOC
#define RS_PIN		(1<<1)

void LCD_RW(char act);
void LCD_E(char act);
void LCD_RS(char act);
void LCD_OUT(int dat);

void LCD_RW(char act)
{
	// RW = L
}

void LCD_E(char act)
{
	if(act){
		HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_RESET);
	}
}

void LCD_RS(char act)
{
	if(act){
		HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);
	}
}

void LCD_OUT(int dat)
{
	int pin;
	pin = dat & 0x0f0;
	HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_SET);
	pin = (~pin) & 0x0f0;
	HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_RESET);
}

void lcd_write8(char reg, char dat);
void lcd_write(char reg, char dat);

// 8bit mode write
void lcd_write8(char reg, char dat)
{
	LCD_RS(reg);
	LCD_OUT(dat);
	LCD_E(ON);
	HAL_Delay(1);
	LCD_E(OFF);
	HAL_Delay(2);
}

// 4bit mode write
void lcd_write(char reg, char dat)
{
	LCD_RS(reg);
	LCD_OUT(dat);
	LCD_E(ON);
	HAL_Delay(1);
	LCD_E(OFF);
	dat<<=4;
	LCD_OUT(dat);
	LCD_E(ON);
	HAL_Delay(1);
	LCD_E(OFF);
}

void LcdCls()
{
	lcd_write(CMD, 1);
}

void LcdDisplayMode(char disp, char cursor, char blink)
{
	char mode = 0x08;
	if(disp) mode |= 0x04;
	if(cursor) mode |= 0x02;
	if(blink) mode |= 0x01;
	lcd_write(CMD, mode);
}

void LcdInit()
{
	// LCDの初期化
	LCD_RW(OUT);
	HAL_Delay(30);
	lcd_write8(CMD, 0x30);		// Function 8bit
	HAL_Delay(5);
	lcd_write8(CMD, 0x30);		// Function 8bit
	HAL_Delay(5);
	lcd_write8(CMD, 0x30);		// Function 8bit
	HAL_Delay(5);

	lcd_write8(CMD, 0x20);		// Function 4bit
	HAL_Delay(5);
	lcd_write8(CMD, 0x20);		// Function 4bit
	HAL_Delay(5);
	lcd_write8(CMD, 0x20);		// Function 4bit
	HAL_Delay(5);

	LcdDisplayMode(0, 0, 0);
	HAL_Delay(5);
	LcdCls();
	HAL_Delay(5);
	lcd_write(CMD, 0x06);			// Entry Mode Set
	HAL_Delay(40);
	LcdDisplayMode(1, 1, 1);
	HAL_Delay(5);
}

void LcdPutc(char c)
{
	lcd_write(DAT, c);
}

void LcdPuts(char *str)
{
	while(*str){
		LcdPutc(*str);
		str++;
	}
}

void LcdXy(char x, char y)
{
	unsigned char adr;
	adr = (x+(y%2)*0x40) | 0x80;
	lcd_write(CMD, adr);
	HAL_Delay(10);
}





#endif /* LCD_H_ */
