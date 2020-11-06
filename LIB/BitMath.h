/*
 * BitMath.h
 *
 *  Created on: Oct 23, 2020
 *      Author: Eng_Fawzi
 */

#ifndef MCAL_DIO_INC_BITMATH_H_
#define MCAL_DIO_INC_BITMATH_H_

#define SET_BIT(REG,BIT)           	(REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)			(REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) 		(REG^=(1<<BIT))
#define CHECK_BIT(REG,BIT)			(REG&=(1<<BIT))

#endif /* MCAL_DIO_INC_BITMATH_H_ */
