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
#include <avr/io.h>
#include "gpio.h"
#include "timer.h"
#include "common_macros.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

#if(BOTH_TIMERS == TRUE)
	Timer0_ConfigType MotorPWM_Mode = {prescaler_8,F_PWM, Clear_Pin, 0, 0};
#else
	#if(TIMER == TIMER0)
		Timer_ConfigType MotorPWM_Mode = {prescaler_8,F_PWM, Clear_Pin, 0, 0};
    #else
		#error motor works in this project with Timer 0 only.
	#endif
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initializing the DC Motor driver.
 * The Function is responsible for setup of direction for the two motor pins through the GPIO driver.
 */
void DcMotor_init(void){
	/* Setting PB0, PB1 as output to drive DC Motor*/
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN1,PIN_OUTPUT);

	/* Setting Logic Low to both pins */
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN0,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);
}

/*
 * Description :
 * The function responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */

#define Customizable_Speed TRUE
#if (Customizable_Speed == TRUE)
	void DcMotor_Rotate(DcMotor_State state, uint8 speed){

		GPIO_writePin(MOTOR_PORT,MOTOR_PIN0,(GET_BIT(state,MOTOR_PIN0))); /* Applying 1st bit of state to Motor's 1st pin */
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,(GET_BIT(state,MOTOR_PIN1))); /* Applying 2nd bit of state to Motor's 2nd pin */


		GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

		MotorPWM_Mode.Compare_Value = speed * One_Percent;
		Timer0_init(&MotorPWM_Mode);
	}

#else
	void DcMotor_Rotate(DcMotor_State state){

			GPIO_writePin(MOTOR_PORT,MOTOR_PIN0,(GET_BIT(state,MOTOR_PIN0))); /* Applying 1st bit of state to Motor's 1st pin */
			GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,(GET_BIT(state,MOTOR_PIN1))); /* Applying 2nd bit of state to Motor's 2nd pin */

			GPIO_setupPinDirection(MOTOR_PORT,PIN3_ID,PIN_OUTPUT);

			Timer0_init(MotorPWM_Mode);
		}
#endif

