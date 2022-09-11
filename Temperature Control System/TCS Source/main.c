 /******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Application file for Mini_Project3
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "lcd.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

ADC_ConfigType MyConfig = {internal, prescale_8}; /* choosing configurations as specified */

int main(void){
	uint8 temp;

	LCD_init();    			/* initialize LCD driver */
	ADC_init(&MyConfig);    /* initialize ADC driver with required configurations */
	DcMotor_init();			/* initialize DC Motor driver */


	LCD_displayStringRowColumn(1,3,"Temp =    C");

	while(1){
		temp = LM35_getTemperature();
		if(temp<30){
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			DcMotor_Rotate(stop,0);
		}

		else if(temp>=30 && temp<60){
			LCD_displayStringRowColumn(0,3,"FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			DcMotor_Rotate(rotate_clockwise,25);
		}

		else if(temp>=60 && temp<90){
			LCD_displayStringRowColumn(0,3,"FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			DcMotor_Rotate(rotate_clockwise,50);
		}

		else if(temp>= 90 && temp<120){
			LCD_displayStringRowColumn(0,3,"FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);

			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}

			DcMotor_Rotate(rotate_clockwise,75);
		}
		else if(temp >= 120){
			LCD_displayStringRowColumn(0,3,"FAN IS ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);

			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}

			DcMotor_Rotate(rotate_clockwise,100);
		}

	}
}
