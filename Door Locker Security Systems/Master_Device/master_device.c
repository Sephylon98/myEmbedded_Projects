 /******************************************************************************
 *
 * Application: Door Locker Security System (Final Project )
 *
 * File Name: master_device.c
 *
 * Description: source file for application
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "lcd.h"
#include "uart.h"
#include "keypad.h"
#include "custom_delay.h"
#include <util/delay.h>

UART_Config MyConfig = {9600, DoubleSpeed_mode, Disabled, one_bit, eight_bits};

uint8 Current_password[5];
uint8 Old_password[5];

uint8 Authenticate_Password(void){


	uint8 password_counter  = 0;
	uint8 Authentication_counter = 0;
	uint8 temp;

	for(Authentication_counter = 0; Authentication_counter<2; Authentication_counter++){
		LCD_displayStringRowColumn(0,0,"Please enter pass:");
		LCD_displayStringRowColumn(1,0,"*****");
		LCD_moveCursor(1,0);
		while(password_counter<=4){
			temp = KEYPAD_getPressedKey();

			if((temp<= 9) && (temp >= 0)){
				if(Authentication_counter == 0){
					Old_password[password_counter] = temp;
				  LCD_intgerToString(Old_password[password_counter]);
				}
				else if(Authentication_counter == 1){
					Current_password[password_counter] = temp;
					LCD_intgerToString(Current_password[password_counter]);
				}
				password_counter++;
				if(password_counter == 5){
					_delay_ms(300);
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,0,"Press Enter");
					while(KEYPAD_getPressedKey() != 13);
					LCD_clearScreen();
					LCD_moveCursor(0,0);
				}
			}
			_delay_ms(600);
		}
		password_counter = 0;
	}

	Authentication_counter = 0;

	for(password_counter = 0;  password_counter<5; password_counter++){
		if(Old_password[password_counter] == Current_password[password_counter]){
			Authentication_counter++;
		}
	}

	if(Authentication_counter==5){
		Authentication_counter = 0;
		return 1;
	}

	Authentication_counter = 0;
	return 0;
}

uint8 Confirm_Password(void){
	uint8 password_counter  = 0;
	uint8 Authentication_counter = 0;
	uint8 temp;

		//while(UART_recieveByte() != 'R');
		//UART_sendByte('G');
		for(Authentication_counter = 0; Authentication_counter <5; Authentication_counter++){
			Current_password[Authentication_counter] = UART_recieveByte();
		}
		Current_password[5] = '\0';
		Authentication_counter = 0;

		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"Please enter pass:");
		LCD_displayStringRowColumn(1,0,"*****");
		LCD_moveCursor(1,0);
		while(password_counter<=4){
			temp = KEYPAD_getPressedKey();
			if((temp<= 9) && (temp >= 0)){
				Old_password[password_counter] = temp;
				LCD_intgerToString(Old_password[password_counter]);
				password_counter++;
				if(password_counter == 5){
					_delay_ms(300);
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,0,"Press Enter");
					while(KEYPAD_getPressedKey() != 13);
					LCD_clearScreen();
					LCD_moveCursor(0,0);
				}
			}
			_delay_ms(600);
		}
		password_counter = 0;

	for(password_counter = 0;  password_counter<5; password_counter++){
		if(Old_password[password_counter]+'0' == Current_password[password_counter]){
			Authentication_counter++;
			LCD_displayCharacter(Authentication_counter);
		}
	}
	if(Authentication_counter==5){
		Authentication_counter = 0;
		return 1;
	}
	Authentication_counter = 0;
	return 0;
}

void security_mech(void){

	uint8 temp;
	uint8 loop_counter = 0;
	uint8 buzzer_counter = 0;
	LCD_displayStringRowColumn(0,0,"+: open door");
	LCD_displayStringRowColumn(1,0,"-: change password");

	temp = KEYPAD_getPressedKey();
	_delay_ms(500);
	if(temp == '+'){
		UART_sendByte('+');
		for(loop_counter = 0; loop_counter<3; loop_counter++){
			temp = Confirm_Password();
			if(temp == 1){
				UART_sendByte('M');
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"Stand by");
				SetDelay_sec_times(33);
				LCD_clearScreen();
				break;
			}

			if(temp == 0){
				UART_sendByte('+');
				buzzer_counter++;
				if(buzzer_counter == 3){
					UART_sendByte('B');
					LCD_displayStringRowColumn(0,5,"Error!");
					LCD_displayStringRowColumn(1,0,"wrong password!");
					SetDelay_sec_times(1);
					LCD_clearScreen();
					SetDelay_sec_times(60);
					buzzer_counter = 0;
				}
			}
		}
		loop_counter = 0;
	}

	else if(temp == '-'){
		uint8 new_pass_counter = 0;
		LCD_clearScreen();
		UART_sendByte('-');
		for(loop_counter = 0; loop_counter<3; loop_counter++){
			temp = Authenticate_Password();
			if(temp == 1){
				UART_sendByte('U');
				for(new_pass_counter = 0; new_pass_counter<5; new_pass_counter++){
					UART_sendByte(Current_password[new_pass_counter]+'0');
					_delay_ms(100);
				}
				loop_counter = 3;
			}
			if(temp == 0){
				buzzer_counter++;
				if(buzzer_counter == 3){
					UART_sendByte('B');
					LCD_displayStringRowColumn(0,5,"Error!");
					LCD_displayStringRowColumn(1,0,"wrong password!");
					SetDelay_sec_times(1);
					LCD_clearScreen();
					SetDelay_sec_times(60);
					buzzer_counter = 0;
				}
			}
		}
		loop_counter = 0;
	}
}

int main(void){
	uint8 check_pass = 0;
	uint8 uart_counter = 0;
	LCD_init();
	UART_init(&MyConfig);
	do{
		check_pass = Authenticate_Password();
		if(check_pass == 1){
			for(uart_counter = 0; uart_counter<5; uart_counter++){
				UART_sendByte(Current_password[uart_counter]+'0');
				_delay_ms(100);
			}
		}
	}while(check_pass!=1);


	while(1){
		security_mech();
	}
}






