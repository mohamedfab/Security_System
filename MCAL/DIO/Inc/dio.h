/*
 * dio.h
 *
 *  Created on: Oct 24, 2020
 *      Author: Eng_Fawzi
 */

#ifndef MCAL_DIO_INC_DIO_H_
#define MCAL_DIO_INC_DIO_H_

#include "BitMath.h"

typedef enum {
	  RESET,
	  SET
	}pinVal;

typedef enum {
	INPUT,
	OUTPUT
}pinDir;

void dioPinDir(char* port,unsigned char pin,pinDir dir);
void dioPinsDir(char* port,unsigned char mask,pinDir dir);
void dioWritePin(char* port,unsigned char pin,pinVal val);
void dioWritePins(char* port,unsigned char mask,char val);
unsigned char dioReadPin(char* port,unsigned char pin);


#endif /* MCAL_DIO_INC_DIO_H_ */
