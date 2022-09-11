 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the buzzer driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Buzzer_PIN PIN7_ID
#define Buzzer_PORT PORTD_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_init
 * [Description]: Initialize the Buzzer's PIN as required.
 * 				  Setup Buzzer's state: ON , OFF.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_init(void);

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_enable
 * [Description]: Enables buzzer.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_enable(void);

/* -----------------------------------------------------------------------------
 * [Function Name]: Buzzer_disable
 * [Description]: Disables buzzer.
 * [Args]: void.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Buzzer_disable(void);
#endif /* BUZZER_H_ */
