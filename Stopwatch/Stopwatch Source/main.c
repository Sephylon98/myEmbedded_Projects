/*
 * main.c
 *
 *  Created on: May 2, 2022
 *      Author: Midox
 */



// CPU Frequencry = 1 Mhz

#include "Macros.h"
#include <avr/interrupt.h>
#include <util/delay.h>

#define Total_Seconds 86400

void External_Interrupt_Init(void);
void Timer1_CTC_Init(unsigned short tick);
void Display(unsigned char hour2, unsigned char hour1, unsigned char min2, unsigned char min1, unsigned char sec2, unsigned char sec1);


//unsigned char stopwatch_counter = 0;

unsigned char digit[10] = {0,1,2,3,4,5,6,7,8,9};
unsigned char hour2, hour1, min2, min1, sec2, sec1 = 0;

int main(void){

	DDRC = 0x0F;
	DDRA = 0x3F;

	External_Interrupt_Init();
	Timer1_CTC_Init(976);

	while(1){
		Display(hour2, hour1, min2, min1, sec2 ,sec1);
	}
}

void External_Interrupt_Init(void){

	SREG = 0x80; //Enable Global Interrupt

	/* INT0, INT1 */
	DDRD = 0x00; //PORTD Input
	PORTD = 0x04; //Turn Pull up on PD2
	MCUCR |= (1<<ISC01)|(1<<ISC11)|(1<<ISC10) ; //INT0 Falling Edge , INT1 Rising Edge
	GICR |= (1<<INT0)|(1<<INT1); //Enable INT0, INT1 Interrupts
	/* ------------ */

	/* INT2 */
	DDRB = 0x00; //PORTB Input
	PORTB = 0x04; //Turn Pull up on PB2
	MCUCSR &= ~(1<<ISC2); //INT2 Falling Edge
	GICR |= (1<<INT2); //Enable INT2 Interrupt
	/* ---- */

}


void Timer1_CTC_Init(unsigned short tick){
	TCNT1 = 0;
	OCR1A = tick;
	TIMSK |= (1<<OCIE1A);
	TCCR1B |= (1<<WGM12)|(1<<CS10)|(1<<CS12); //CTC Mode, 1024 Pre-scaler
}


void Display(unsigned char hour2, unsigned char hour1, unsigned char min2, unsigned char min1, unsigned char sec2 , unsigned char sec1){
	Control_Port = (1<<SL1);
	Data_Port = digit[sec1];
	_delay_ms(1);

	Control_Port = (1<<SL2);
	Data_Port = digit[sec2];
	_delay_ms(1);

	Control_Port = (1<<SL3);
	Data_Port = digit[min1];
	_delay_ms(1);

	Control_Port = (1<<SL4);
	Data_Port = digit[min2];
	_delay_ms(1);

	Control_Port = (1<<SL5);
	Data_Port = digit[hour1];
	_delay_ms(1);

	Control_Port = (1<<SL6);
	Data_Port = digit[hour2];
	_delay_ms(1);

}

ISR(TIMER1_COMPA_vect){
	sec1++;		//increment sec1
	if (sec1>9)	{
		sec1 = 0;	//if sec1 = 10, reset sec1 to 0
		sec2++;	//increment sec2
		if(sec2==6){
			sec2 = 0; //if sec2 = 7 reset sec2 to 0
			min1++; //increment min1
			if(min1>9){
				min1 = 0; //if min1 = 10 reset min1 to 0
				min2++; //increment min2
				if(min2==6){
					min2 = 0; //if min2 = 7 reset min2 to 0
					hour1++; //increment hour1
					if(hour1>9){
						hour1 = 0; //if hour1 = 10 reset hour1 to 0
						hour2++; //increment hour2
						if(hour2 > 2){
							hour2 = hour1 = min2 = min1 = sec2 = sec1 = 0;
						}
					}
				}
			}
		}
	}
}


ISR(INT0_vect){
	hour2 = hour1 = min2 = min1 = sec2 = sec1 = 0;
}



ISR(INT1_vect){
	TCCR1B &= ~(1<<CS10) & ~(1<<CS12);
}

ISR(INT2_vect){
	TCCR1B |= (1<<CS10)|(1<<CS12);
}

