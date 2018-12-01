/*
 * LED.c
 *
 *  Created on: Nov 19, 2018
 *      Author: Andy
 */

#include "Bits.h"
#include "GPIO.h"
#include "Game.h"
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
	uint8 led;
	uint32 randomValue;
	randomValue = Flex_return_counter();
	randomValue = randomValue % 9;
	switch(randomValue){
	case B1:
		led = B1;
		break;
	case B2:
		led = B2;
		break;
	case B3:
		led = B3;
		break;
	case B4:
		led = B4;
		break;
	case B5:
		led = B5;
		break;
	case B6:
		led = B6;
		break;
	case B7:
		led = B7;
		break;
	case B8:
		led = B8;
		break;
	case B9:
		return LED9;
		break;
	default:
		led = NULL;
		break;
	}
	return led;
}
