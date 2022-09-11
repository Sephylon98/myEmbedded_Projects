 /******************************************************************************
 *
 * Module: Button
 *
 * File Name: button.c
 *
 * Description: Source file for the Button driver.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "button.h"
#include <avr/io.h>
#include "../../MCAL/GPIO Driver/gpio.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: Button_init
 * [Description]: Initialize the Button driver as required.
 * [Args]: Port Number & Pin Number .
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Button_init(uint8 PortNum, uint8 PinNum){
	GPIO_setupPinDirection(PortNum, PinNum, PIN_INPUT);
	GICR |= (1<<INT0);
	MCUCR |= (1<<ISC01);
}


