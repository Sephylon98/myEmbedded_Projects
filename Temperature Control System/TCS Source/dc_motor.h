 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC Motor driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PIN0 PIN0_ID
#define MOTOR_PIN1 PIN1_ID
#define ONE_PERCENT_COUNT 2.55 //Actually 2.56 but to avoid overflow in Timer 0 I've set it to 2.55

/*******************************************************************************
 *                                Enums                                        *
 *******************************************************************************/
typedef enum{
	stop, rotate_clockwise, rotate_anti_clockwise
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the DC Motor driver.
 * The Function is responsible for setup of direction for the two motor pins through the GPIO driver.
 */
void DcMotor_init(void);
/*
 * Description :
 * The function responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
