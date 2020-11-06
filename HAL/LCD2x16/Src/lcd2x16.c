/*
 * lcd2x16.c
 *
 *  Created on: Oct 24, 2020
 *      Author: Eng_Fawzi
 */
#include "lcd2x16.h"
#include "dio.h"
#include <util/delay.h>
#include <stdio.h>
static void HAL_lcdEnablePulse()
{
	dioWritePin(LCD_CTRL_PORT,EN,SET);
	_delay_us(1);
	dioWritePin(LCD_CTRL_PORT,EN,RESET);
	_delay_ms(1);
}
void HAL_lcdWrite(char data)
{
	//LCD_DATA_PORT->PORT=(LCD_DATA_PORT->PORT&0X0F)|(data&0xf0);
	dioWritePins(LCD_DATA_PORT,LCD_MASK,data&0xF0);
	HAL_lcdEnablePulse();
	//LCD_DATA_PORT->PORT=(LCD_DATA_PORT->PORT&0X0F)|(data<<4);
	dioWritePins(LCD_DATA_PORT,LCD_MASK,data<<4);
	HAL_lcdEnablePulse();
}
void HAL_lcdCmd(char cmd)
{
	dioWritePin(LCD_CTRL_PORT,RW,RESET);   //write mode
	dioWritePin(LCD_CTRL_PORT,RS,RESET);   //cmd mode
	HAL_lcdWrite(cmd);
}
void HAL_lcdDispChar(char data)
{
	dioWritePin(LCD_CTRL_PORT,RW,RESET);   //write mode
	dioWritePin(LCD_CTRL_PORT,RS,SET);   //data mode
	HAL_lcdWrite(data);
}
void HAL_lcdDispString(char *str)
{
	while(*str !='\0')
	{
		HAL_lcdDispChar(*str++);
	}
}
void HAL_lcdGotoRowColumn(char row,char column)
{
	switch (row)
	{
		case 0:
			HAL_lcdCmd(0x80+column);
		break;
		case 1:
			HAL_lcdCmd(0xC0+column);
		break;
		case 2:
			HAL_lcdCmd(0x94+column);
		break;
		case 3:
			HAL_lcdCmd(0xD4+column);
		break;
	}
}
void HAL_lcdDispInteger(uint16_t intValue)
{
	char buffer[17]={0};
	sprintf(buffer,"%d",intValue);
	HAL_lcdDispString(buffer);
}
void HAL_lcdInit()
{
	/*configure micro controller pins*/


	dioPinDir(LCD_CTRL_PORT,RS,OUTPUT);
	dioPinDir(LCD_CTRL_PORT,RW,OUTPUT);
	dioPinDir(LCD_CTRL_PORT,EN,OUTPUT);

	DDRD|=0xF0;
	PORTD&=0x0F;

	dioWritePin(LCD_CTRL_PORT,RS,RESET);
	dioWritePin(LCD_CTRL_PORT,RW,RESET);
	dioWritePin(LCD_CTRL_PORT,EN,RESET);

	/*initialize LCD*/
	_delay_ms(10);
	dioWritePin(LCD_CTRL_PORT,RW,RESET);
	dioWritePin(LCD_CTRL_PORT,RS,RESET);

	dioWritePin(LCD_DATA_PORT,4,SET);
	dioWritePin(LCD_DATA_PORT,5,SET);
	_delay_us(10);
	HAL_lcdEnablePulse();
	HAL_lcdEnablePulse();
	HAL_lcdEnablePulse();

	dioWritePin(LCD_DATA_PORT,4,RESET);
	_delay_us(10);
	HAL_lcdEnablePulse();

	HAL_lcdCmd(_LCD_4BIT_MODE);
	HAL_lcdCmd(_LCD_CURSOR_ON);
	HAL_lcdCmd(_LCD_CLEAR);
	HAL_lcdCmd(_LCD_CURSOR_INCREMENT);
}

