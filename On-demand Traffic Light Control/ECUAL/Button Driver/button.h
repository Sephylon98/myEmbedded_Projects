 /******************************************************************************
 *
 * Module: Button
 *
 * File Name: button.h
 *
 * Description: Header file for the Button driver.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Utilities/std_types.h"

/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/

#define ButtonPORT 3
#define ButtonPin  2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: Button_init
 * [Description]: Initialize the Button driver as required.
 * [Args]: Port Number & Pin Number .
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void Button_init(uint8 PortNum, uint8 PinNum);

#endif /* end of BUTTON_H_ */
