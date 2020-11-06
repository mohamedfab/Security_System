/********************************
 * dio.c
 * Created on: Oct 24, 2020
 * Author: Eng_Fawzi
 ********************************/

#include "dio.h"

/*
 * Description	:
 * parm[in] 	:
 * param[out]	:
 */
void dioPinDir(char* port,unsigned char pin,pinDir dir)
{
	port--;
	if (dir == 1)
	{
		SET_BIT(*port,pin);
	}
	else if (dir ==0 )
	{
		CLEAR_BIT(*port,pin);
	}
}
void dioPinsDir(char* port,unsigned char mask,pinDir dir)
{
	port--;
	*port&=mask;
	if (dir == OUTPUT)
	{
		*port|=(0xFF&~mask);
	}
	else if (dir == INPUT)
	{
		*port&=mask;
	}
}
void dioWritePins(char* port,unsigned char mask,char val)
{
	*port&=mask;
	*port|=val;
}
void dioWritePin(char* port,unsigned char pin,pinVal val)
{
	if (val == 1)
	{
		SET_BIT(*port,pin);
	}
	else if (val == 0)
	{
		CLEAR_BIT(*port,pin);
	}
}
unsigned char dioReadPin(char* port,unsigned char pin)
{
	port-=2;
	if ((CHECK_BIT(*port,pin)) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
