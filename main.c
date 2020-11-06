/****************************************
 * main.c
 * Created on: Oct 23, 2020
 * Author: Eng_Fawzi
 ****************************************/
#define LED   (1u)

#include <avr/io.h>
#include <util/delay.h>
#include "BitMath.h"
#include "lcd2x16.h"

int main()
	{
	    DDRD=0xFF;
	    HAL_lcdInit();
		while (1)
			{
				SET_BIT(PORTD,LED);
				_delay_ms(500);
				CLEAR_BIT(PORTD,LED);
				_delay_ms(500);
			}
		return 0;
	}
