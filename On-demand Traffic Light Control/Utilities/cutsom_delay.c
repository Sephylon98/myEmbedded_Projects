 /******************************************************************************
 *
 * Module: Delay elements
 *
 * File Name: custom_delay.c
 *
 * Description: Source file for delaying functions.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "custom_delay.h"
#include "../MCAL/Timers Driver/timer.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* F_CPU = 1M Hz */
/* This will generate compare match every 1 sec --> 15625 OCR1A Value , F_CPU = 125K Hz*/
Timer_ConfigType time = {prescaler_64, CTC_OCR1A_mode, Pin_Disconnected, Pin_Disconnected, 0 , 15625 , 0};

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Function responsible for setting delays. */
void delay_init(void){
	Timer_init(&time);
	//Timer1_Enable_COMP_Interrupt();
	//Timer_setCallBack(delay_five_secs);
}


void delay_sec(void){
	Timer_init(&time);
	while(!(TIFR & (1<<OCF1A)));
	TIFR |= (1<<OCF1A);
	Timer_deinit();
}

