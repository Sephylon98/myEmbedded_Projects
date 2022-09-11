 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for the led driver.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "led.h"
#include "../../MCAL/GPIO Driver/gpio.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: LED_Init
 * [Description]: Initialize the LED driver as required.
 * [Args]: Port Number & Pin Number .
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_init(uint8 PortNum, uint8 PinNum){
	GPIO_setupPinDirection(PortNum, PinNum, PIN_OUTPUT);
	GPIO_writePin(PortNum, PinNum, LOGIC_LOW);
}

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_ON
 * [Description]: Turns on LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_ON(uint8 PortNum, uint8 PinNum){
	GPIO_writePin(PortNum, PinNum, LOGIC_HIGH);
}

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_OFF
 * [Description]: Turns off LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_OFF(uint8 PortNum, uint8 PinNum){
	GPIO_writePin(PortNum, PinNum, LOGIC_LOW);
}

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_Toggle
 * [Description]: Toggles LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_Toggle(uint8 PortNum, uint8 PinNum){
	GPIO_togglePin(PortNum, PinNum);
}

