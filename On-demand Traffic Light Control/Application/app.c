/******************************************************************************
 *
 * Application: On-demand Traffic light control
 *
 * File Name: app.c
 *
 * Description: source file for On-demand Traffic light control.
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#include "app.h"
#include <avr/interrupt.h> /* To use interrupts */


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

uint8 previousCarFlag;
uint8 currentCarFlag = Green;
uint8 PedestrianFlag;

volatile uint8 InterruptFlag = FALSE;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* -----------------------------------------------------------------------------
 * [Function Name]: APP_start
 * [Description]: Starts the application.
 * [Args]: this function takes void as input.
 * [Returns]: this function returns void.
 * ----------------------------------------------------------------------------*/
void APP_start(void) {
	/* Turn on Global Interrupt */
	SREG = 0x80;

	/* Enable Button */
	Button_init(ButtonPORT, ButtonPin);
	//delay_init();

	/* Traffic Light */
	LED_init(TrafficLight_PORT, TrafficLight_GREEN);
	LED_init(TrafficLight_PORT, TrafficLight_YELLOW);
	LED_init(TrafficLight_PORT, TrafficLight_RED);

	/* Pedestrian sign */
	LED_init(Pedestrian_PORT, Pedestrian_GREEN);
	LED_init(Pedestrian_PORT, Pedestrian_YELLOW);
	LED_init(Pedestrian_PORT, Pedestrian_RED);
}

void App(void) {
	/* Normal Mode */
	uint8 sec_counter;
	switch (currentCarFlag) {
	case Green:
		/* Green Light */
		LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
		previousCarFlag = Green;
		currentCarFlag = Yellow;
		LED_ON(TrafficLight_PORT, TrafficLight_GREEN);
		for (sec_counter = 0; sec_counter < 5; sec_counter++) {
			delay_sec();
		}
//		_delay_ms(5000);
		LED_OFF(TrafficLight_PORT, TrafficLight_GREEN);
		break;
		/* End of Green Light*/

	case Yellow:
		/* Yellow Flashing Light */
		if (previousCarFlag == Green) {
			previousCarFlag = Yellow;
			currentCarFlag = Red;
			for (sec_counter = 0; sec_counter < 5; sec_counter++) {
				LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
				delay_sec();
//				_delay_ms(1000);
			}
			LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
		} else if (previousCarFlag == Red) {
			previousCarFlag = Yellow;
			currentCarFlag = Green;
			for (sec_counter = 0; sec_counter < 5; sec_counter++) {
				LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
				delay_sec();
//				_delay_ms(1000);
			}
			LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
		}
		/* End of yellow flashing light*/
		break;

	case Red:
		/* Red Light */
		previousCarFlag = Red;
		currentCarFlag = Yellow;
		LED_ON(TrafficLight_PORT, TrafficLight_RED);
		for (sec_counter = 0; sec_counter < 5; sec_counter++) {
			delay_sec();
		}
//		_delay_ms(5000);
		LED_OFF(TrafficLight_PORT, TrafficLight_RED);
		/* End of Red Light */
		break;
	}
}

void Traffic_LightsOff(void) {
	LED_OFF(TrafficLight_PORT, TrafficLight_RED);
	LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
	LED_OFF(TrafficLight_PORT, TrafficLight_GREEN);
}

void Pedestrian_LightsOff(void) {
	LED_OFF(Pedestrian_PORT, Pedestrian_RED);
	LED_OFF(Pedestrian_PORT, Pedestrian_YELLOW);
	LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);
}

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(INT0_vect) {
	/* Pedestrian mode */
	uint8 ISR_sec_counter;
	Traffic_LightsOff();
	switch (previousCarFlag) {
	case Red:
		LED_OFF(TrafficLight_PORT, TrafficLight_RED);
		LED_ON(TrafficLight_PORT, TrafficLight_RED);
		LED_ON(Pedestrian_PORT, Pedestrian_GREEN);
		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			delay_sec();
		}
//		_delay_ms(5000);
		LED_OFF(TrafficLight_PORT, TrafficLight_RED);
		LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);
		currentCarFlag = Green;
		Traffic_LightsOff();
		Pedestrian_LightsOff();
		delay_init();
		break;

	case Yellow:
		LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
		LED_ON(Pedestrian_PORT, Pedestrian_RED);

		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
			LED_Toggle(Pedestrian_PORT, Pedestrian_YELLOW);
			delay_sec();
//			_delay_ms(1000);
		}
		LED_OFF(Pedestrian_PORT, Pedestrian_RED);
		LED_OFF(Pedestrian_PORT, Pedestrian_YELLOW);
		LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);

		LED_ON(TrafficLight_PORT, TrafficLight_RED);
		LED_ON(Pedestrian_PORT, Pedestrian_GREEN);
		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			delay_sec();
		}
//		_delay_ms(5000);
		LED_OFF(TrafficLight_PORT, TrafficLight_RED);
		//LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);

		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
			LED_Toggle(Pedestrian_PORT, Pedestrian_YELLOW);
			delay_sec();
//			_delay_ms(1000);
		}
		LED_OFF(Pedestrian_PORT, Pedestrian_YELLOW);
		LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);
		LED_ON(Pedestrian_PORT, Pedestrian_RED);
		LED_ON(TrafficLight_PORT, TrafficLight_GREEN);
		currentCarFlag = Green;
		Traffic_LightsOff();
		Pedestrian_LightsOff();
		delay_init();
		break;

	case Green:
		LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);
		LED_ON(Pedestrian_PORT, Pedestrian_RED);

		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
			LED_Toggle(Pedestrian_PORT, Pedestrian_YELLOW);
			delay_sec();
//			_delay_ms(1000);
		}
		LED_OFF(Pedestrian_PORT, Pedestrian_RED);
		LED_OFF(Pedestrian_PORT, Pedestrian_YELLOW);
		LED_OFF(TrafficLight_PORT, TrafficLight_YELLOW);

		LED_ON(TrafficLight_PORT, TrafficLight_RED);
		LED_ON(Pedestrian_PORT, Pedestrian_GREEN);
		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			delay_sec();
		}
//		_delay_ms(5000);
		LED_OFF(TrafficLight_PORT, TrafficLight_RED);
		//LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);

		for (ISR_sec_counter = 0; ISR_sec_counter < 5; ISR_sec_counter++) {
			LED_Toggle(TrafficLight_PORT, TrafficLight_YELLOW);
			LED_Toggle(Pedestrian_PORT, Pedestrian_YELLOW);
			delay_sec();
//			_delay_ms(1000);
		}

		LED_OFF(Pedestrian_PORT, Pedestrian_YELLOW);
		LED_OFF(Pedestrian_PORT, Pedestrian_GREEN);
		LED_ON(Pedestrian_PORT, Pedestrian_RED);
		LED_ON(TrafficLight_PORT, TrafficLight_GREEN);
		currentCarFlag = Green;
		Traffic_LightsOff();
		Pedestrian_LightsOff();
		delay_init();
		break;
	}
}

