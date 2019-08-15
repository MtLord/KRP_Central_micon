/*
 * LCD.c
 *
 *  Created on: 2019/06/10
 *      Author: —T‘¿
 */

#include <LCD/LCD.hpp>

void LCD::LCD_RW(char act){

}

void LCD::LCD_E(char act)
{
	if(act){
			HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(E_PORT, E_PIN, GPIO_PIN_RESET);
		}
}

void LCD::LCD_RS(char act)
{
	if(act){
			HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);
		}
}

void LCD::LCD_OUT(int dat)
{
	int pin;
	pin = dat & 0x0f0;
	HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_SET);
	pin = (~pin) & 0x0f0;
	HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_RESET);

}

void LCD::lcd_write8(char reg, char dat)
{
	LCD_RS(reg);
		LCD_OUT(dat);
		LCD_E(ON);
		HAL_Delay(1);
		LCD_E(OFF);
		HAL_Delay(2);
}

void LCD::lcd_write(char reg, char dat)
{
	LCD_RS(reg);
		LCD_OUT(dat);//output_b
		LCD_E(ON);
		HAL_Delay(1);
		LCD_E(OFF);
		dat<<=4;
		LCD_OUT(dat);
		LCD_E(ON);
		HAL_Delay(1);
		LCD_E(OFF);
}

void LCD::LcdCls()
{
	lcd_write(CMD, 1);
}

void LCD::LcdPutc(char c)
{
	lcd_write(CMD, 1);
}
void LCD::LcdDisplayMode(char disp, char cursor, char blink)
{
	char mode = 0x08;
		if(disp) mode |= 0x04;
		if(cursor) mode |= 0x02;
		if(blink) mode |= 0x01;
		lcd_write(CMD, mode);
}

void LCD::LcdInit()
{
	// LCD‚Ì‰Šú‰»
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
		LcdDisplayMode(1, 0, 0);
		HAL_Delay(5);
}

void LCD::LcdPuts(char *str)
{
	while(*str)
		{
			LcdPutc(*str);
			str++;
		}
}

void LCD::LcdXy(char x,char y)
{
	unsigned char adr;
	adr = (x+(y%2)*0x40) | 0x80;
	lcd_write(CMD, adr);
	HAL_Delay(10);
}
