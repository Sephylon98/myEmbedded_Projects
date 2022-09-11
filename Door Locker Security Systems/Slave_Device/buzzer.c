 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the buzzer driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "buzzer.h"
#include "common_macros.h"
#include "gpio.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_init
 * [Description]: Initialize the Buzzer's PIN as required.
 * 				  Setup Buzzer's state: ON , OFF.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_init(void){
	GPIO_setupPinDirection(Buzzer_PORT, Buzzer_PIN, PIN_OUTPUT);
	GPIO_writePin(Buzzer_PORT, Buzzer_PIN, LOGIC_LOW);
}

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_enable
 * [Description]: Enables buzzer.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_enable(void){
	GPIO_writePin(Buzzer_PORT, Buzzer_PIN,LOGIC_HIGH);
}

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_disable
 * [Description]: Disables buzzer.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_disable(void){
	GPIO_writePin(Buzzer_PORT, Buzzer_PIN, LOGIC_LOW);
}

