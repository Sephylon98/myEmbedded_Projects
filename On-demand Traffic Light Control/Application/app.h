/******************************************************************************
 *
 * Application: On-demand Traffic light control
 *
 * File Name: app.c
 *
 * Description: header file for On-demand Traffic light control.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../Utilities/custom_delay.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Red 0
#define Green 1
#define Yellow 2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: APP_start
 * [Description]: Starts the application.
 * [Args]: this function takes void as input.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void APP_start(void);
void App(void);
void Traffic_LightsOff(void);
void Pedestrian_LightsOff(void);
#endif /* end of APP_H_ */
