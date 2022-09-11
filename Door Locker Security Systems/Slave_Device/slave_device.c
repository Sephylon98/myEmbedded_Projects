 /******************************************************************************
 *
 * Application: Door Locker Security System (Final Project )
 *
 * File Name: slave_device.c
 *
 * Description: source file for application
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/


#include "dc_motor.h"
#include "buzzer.h"
#include "twi.h"
#include "external_eeprom.h"
#include "lcd.h"
#include "uart.h"
#include "custom_delay.h"
#include <avr/io.h>
#include <util/delay.h>

TWI_ConfigType conf = {1,1,400000};
UART_Config MyConfig = {9600, DoubleSpeed_mode, Disabled, one_bit, eight_bits};
uint8 Current_password[5];


int main(void)
{
	SREG = 0x80;
	uint8 temp;
	uint8 uart_counter = 0;
	uint8 readData[5];
	Buzzer_init();
	DcMotor_init();
	LCD_init();
	TWI_init(&conf);
	UART_init(&MyConfig);

	for(uart_counter = 0; uart_counter<5; uart_counter++){
		readData[uart_counter] = UART_recieveByte();
		EEPROM_writeByte(0x0311, readData[uart_counter]);
		_delay_ms(10);
		EEPROM_readByte(0x0311,&readData[uart_counter]);
		LCD_displayStringRowColumn(0,0,"Saved password!");
		//LCD_displayCharacter(readData[uart_counter]);
	}

	uart_counter = 0;

	while(1) {
		switch(UART_recieveByte()){
		case '+':
			LCD_clearScreen();
			/* Confirm Password compared to one in EEPROM */
			//UART_sendByte('R');
			//while(UART_recieveByte()!= 'G');
			for(uart_counter = 0; uart_counter<5; uart_counter++){
				UART_sendByte(readData[uart_counter]);
				_delay_ms(10);
			}
			break;
		case '-':
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Changing Password");
			_delay_ms(500);
			LCD_clearScreen();
			break;
		case 'M':
			LCD_displayStringRowColumn(0,0,"Opening Door");
			DcMotor_Rotate(rotate_clockwise,100);
			SetDelay_sec_times(15);
			DcMotor_Rotate(stop,0);
			SetDelay_sec_times(3);
			DcMotor_Rotate(rotate_anti_clockwise,100);
			SetDelay_sec_times(15);
			DcMotor_Rotate(stop,0);
			LCD_clearScreen();
			break;
		case 'B':
			LCD_displayStringRowColumn(0,0,"Buzzer ON");
			Buzzer_enable();
			SetDelay_sec_times(60);
			Buzzer_disable();
			LCD_clearScreen();
			break;
		case 'U':
			/* Update PASSWORD to EEPROM */
			for(uart_counter = 0; uart_counter<5; uart_counter++){
				readData[uart_counter] = UART_recieveByte();
				EEPROM_writeByte(0x0311, readData[uart_counter]);
				_delay_ms(10);
				EEPROM_readByte(0x0311,&readData[uart_counter]);
				LCD_displayStringRowColumn(0,0,"Saved password!");
				//LCD_displayCharacter(readData[uart_counter]);
			}
			break;
		}
    }
}

