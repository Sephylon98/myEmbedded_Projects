 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "timer0.h"
#include "common_macros.h"

/*
 * Description :
 * Function responsible for initializing the DC Motor driver.
 * The Function is responsible for setup of direction for the two motor pins through the GPIO driver.
 */
void DcMotor_init(void){
	/* Setting PB0, PB1 as output to drive DC Motor*/
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	/* Setting Logic Low to both pins */
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
}

/*
 * Description :
 * The function responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	GPIO_writePin(PORTB_ID,MOTOR_PIN0,(GET_BIT(state,PIN0_ID))); /* Applying 1st bit of state to Motor's 1st pin */
	GPIO_writePin(PORTB_ID,MOTOR_PIN1,(GET_BIT(state,PIN1_ID))); /* Applying 2nd bit of state to Motor's 2nd pin */

	/* Configuring required speed */
	PWM_Timer0_Start(speed*ONE_PERCENT_COUNT);
}

