 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: timer0.h
 *
 * Description: Header file for the timer0 driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"
#include <avr/io.h>


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing Timer0 in PWM mode.
 * The Function takes required input of duty cycle.
 */
void PWM_Timer0_Start(uint8 set_duty_cycle);


#endif /* TIMER0_H_ */
