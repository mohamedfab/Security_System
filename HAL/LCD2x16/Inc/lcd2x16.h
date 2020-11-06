/***************************************
 * lcd2x16.h
 *  Created on: Oct 24, 2020
 *  Author: Eng_Fawzi
 ***************************************/
#ifndef HAL_LCD2X16_INC_LCD2X16_H_
#define HAL_LCD2X16_INC_LCD2X16_H_

#include "lcd2x16_cfg.h"
#include <avr/io.h>

#define RS					      0
#define RW						  1
#define EN						  2

#define LCD_DATA_PORT		     &PORTD  //MSB 4 bits
#define LCD_CTRL_PORT		     &PORTD

#define LCD_MASK     0x0F

typedef enum
{
	_LCD_CLEAR=0x01,
	_LCD_CURSOR_OFF=0x0C,
	_LCD_CURSOR_ON=0x0F,
	_LCD_4BIT_MODE=0x28,
	_LCD_8BIT_MODE=0x38,
	_LCD_ON=0x0F,
	_LCD_CURSOR_UNDERLINE=0x0E,
	_LCD_CURSOR_SHIFT_LEFT=0x10,
	_LCD_CURSOR_SHIFT_RIGHT=0x14,
	_LCD_CURSOR_INCREMENT=0x06
}lcdCmd_t;

void HAL_lcdWrite(char);
void HAL_lcdCmd(char);
void HAL_lcdDispChar(char);
void HAL_lcdDispString(char *);
void HAL_lcdGotoRowColumn(char,char);
void HAL_lcdDispInteger(uint16_t);
void HAL_lcdInit();

#endif /* HAL_LCD2X16_INC_LCD2X16_H_ */
