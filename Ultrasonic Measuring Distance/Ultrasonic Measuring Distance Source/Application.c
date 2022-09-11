 /******************************************************************************
 *
 * Application: Ultrasonic (Mini Project 4)
 *
 * File Name: Application.c
 *
 * Description: source file for application
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "ultrasonic.h"

int main(void){

	uint16 Distance = 0;

	/* Enable Global interrupt */
	SREG = 0x80;

	/* Initialize LCD, Ultrasonic drivers */
	LCD_init();
	Ultrasonic_init();

	/* Setting Up LCD Look */
	LCD_displayString("Distance = ");
	LCD_moveCursor(0,14);
	LCD_displayString("cm");

	while(1){

		Distance = Ultrasonic_readDistance();
		_delay_ms(20);
		if(Distance<10){
			LCD_moveCursor(0,11);
			LCD_intgerToString(Distance);
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}
		else if(Distance>=10 && Distance <100){
			LCD_moveCursor(0,11);
			LCD_intgerToString(Distance);
			LCD_displayCharacter(' ');
		}

		else if(Distance >=100){
			LCD_moveCursor(0,11);
			LCD_intgerToString(Distance);
		}
	}
}
