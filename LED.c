/*
 * LED.c
 *
 *  Created on: Nov 19, 2018
 *      Author: Andy
 */

#include "Bits.h"
#include "GPIO.h"
#include "Flex.h"
#include "LED.h"

/*LED initialization*/
void LED_init(){
	gpio_pin_control_register_t config = GPIO_MUX1;

	GPIO_clock_gating(GPIO_A);
	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_C);

	/*Pin configuration for leds from push buttons*/
	GPIO_pin_control_register(GPIO_B, BIT2, &config); /*Led 1*/
	GPIO_pin_control_register(GPIO_B, BIT3, &config); /*Led 2*/
	GPIO_pin_control_register(GPIO_B, BIT10, &config); /*Led 3*/
	GPIO_pin_control_register(GPIO_B, BIT11, &config); /*Led 4*/
	GPIO_pin_control_register(GPIO_B, BIT20, &config); /*Led 5*/
	GPIO_pin_control_register(GPIO_C, BIT10, &config); /*Led 6*/
	GPIO_pin_control_register(GPIO_C, BIT11, &config); /*Led 7*/
	GPIO_pin_control_register(GPIO_C, BIT4, &config); /*Led 8*/
	GPIO_pin_control_register(GPIO_A, BIT0, &config); /*Led 9*/

	/*Output configuration for leds from push buttons*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, BIT2); /*Led 1*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, BIT3); /*Led 2*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, BIT10); /*Led 3*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, BIT11); /*Led 4*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, BIT20); /*Led 5*/
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, BIT10); /*Led 6*/
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, BIT11); /*Led 7*/
	GPIO_data_direction_pin(GPIO_C, GPIO_OUTPUT, BIT4); /*Led 8*/
	GPIO_data_direction_pin(GPIO_A, GPIO_OUTPUT, BIT0); /*Led 9*/
}

/*Random*/
uint32 LED_random (){
	uint32 randomValue;
	randomValue = FTM0->CNT;
	randomValue = randomValue % 9;
	switch(randomValue){
	case LED1:
		return LED1;
		break;
	case LED2:
		return LED2;
		break;
	case LED3:
		return LED3;
		break;
	case LED4:
		return LED4;
		break;
	case LED5:
		return LED5;
		break;
	case LED6:
		return LED6;
		break;
	case LED7:
		return LED7;
		break;
	case LED8:
		return LED8;
		break;
	case LED9:
		return LED9;
		break;
	default:
		return LED_NULL;
		break;
	}

}
