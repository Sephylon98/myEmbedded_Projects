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

#ifndef LED_H_
#define LED_H_

#include "../../Utilities/std_types.h"

/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/

#define TrafficLight_PORT    0
#define TrafficLight_GREEN   0
#define TrafficLight_YELLOW  1
#define TrafficLight_RED     2

#define Pedestrian_PORT     1
#define Pedestrian_GREEN    0
#define Pedestrian_YELLOW   1
#define Pedestrian_RED      2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: LED_Init
 * [Description]: Initialize the LED driver as required.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_init(uint8 PortNum, uint8 PinNum);

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_ON
 * [Description]: Turns on LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_ON(uint8 PortNum, uint8 PinNum);

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_OFF
 * [Description]: Turns off LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_OFF(uint8 PortNum, uint8 PinNum);

/* -----------------------------------------------------------------------------
 * [Function Name]: LED_Toggle
 * [Description]: Toggles LED.
 * [Args]: Port Number & Pin Number.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void LED_Toggle(uint8 PortNum, uint8 PinNum);

#endif /* end of LED_H_ */
