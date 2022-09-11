/*
 * Macros.h
 *
 *  Created on: May 2, 2022
 *      Author: Midox
 */

#ifndef MACROS_H_
#define MACROS_H_


#include<avr/io.h>

#define Data_Port PORTC
#define Control_Port PORTA
#define SL1 PA0
#define SL2 PA1
#define SL3 PA2
#define SL4 PA3
#define SL5 PA4
#define SL6 PA5

#define SET_SEC1 PORTA |= (1<<0)
#define SET_SEC2 PORTA |= (1<<1)
#define SET_MIN1 PORTA |= (1<<2)
#define SET_MIN2 PORTA |= (1<<3)
#define SET_HOUR1 PORTA |= (1<<4)
#define SET_HOUR2 PORTA |= (1<<5)

#define CLEAR_SEC1 PORTA &= ~(1<<0)
#define CLEAR_SEC2 PORTA &= ~(1<<1)
#define CLEAR_MIN1 PORTA &= ~(1<<2)
#define CLEAR_MIN2 PORTA &= ~(1<<3)
#define CLEAR_HOUR1 PORTA &= ~(1<<4)
#define CLEAR_HOUR2 PORTA &= ~(1<<5)

#define Toggle_SEC1 PORTA ^= (1<<0)
#define Toggle_SEC2 PORTA ^= (1<<1)
#define Toggle_MIN1 PORTA ^= (1<<2)
#define Toggle_MIN2 PORTA ^= (1<<3)
#define Toggle_HOUR1 PORTA ^= (1<<4)
#define Toggle_HOUR2 PORTA ^= (1<<5)


#endif /* MACROS_H_ */
