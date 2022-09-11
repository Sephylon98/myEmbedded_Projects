 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                                Enums                                        *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,internal=3
}ADC_ReferenceVoltage;

typedef enum{
	default_prescale, prescale_2, prescale_4, prescale_8, prescale_16, prescale_32, prescale_64, prescale_128
}ADC_Prescaler;

/*******************************************************************************
 *                                Structures                                   *
 *******************************************************************************/
typedef struct{
 ADC_ReferenceVoltage ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
