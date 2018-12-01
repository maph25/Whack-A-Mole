/*
 * Game.c
 *
 *  Created on: Nov 30, 2018
 *      Author: Andy
 */

#include "Bits.h"
#include "LED.h"
#include "UART.h"
#include "GPIO.h"
#include "TeraTerm.h"
#include "Game.h"
#include "Buttons.h"
#include "PIT.h"
#include "Delay.h"

uint8 Game_decode_port_led(uint32 random){
	uint8 port;
	switch(random){
	case B1:
		port = GPIO_B;
		break;
	case B2:
		port = GPIO_B;
		break;
	case B3:
		port = GPIO_B;
		break;
	case B4:
		port = GPIO_B;
		break;
	case B5:
		port = GPIO_B;
		break;
	case B6:
		return GPIO_C;
		break;
	case B7:
		port = GPIO_C;
		break;
	case B8:
		port = GPIO_C;
		break;
	case B9:
		port = GPIO_A;
		break;
	default:
		port = NULL;
		break;
	}
	return port;
}

uint8 Game_decode_bit_led(uint32 random){
	uint8 pin;
	switch(random){
	case B1:
		pin = BIT2;
		break;
	case B2:
		pin = BIT3;
		break;
	case B3:
		pin = BIT10;
		break;
	case B4:
		pin = BIT11;
		break;
	case B5:
		pin = BIT20;
		break;
	case B6:
		pin = BIT10;
		break;
	case B7:
		pin = BIT11;
		break;
	case B8:
		pin = BIT4;
		break;
	case B9:
		pin = BIT0;
		break;
	default:
		pin = NULL;
		break;
	}
	return pin;
}

uint8 Game_difficulty(){
	uint8 difficulty;
	uint8 op;
	TeraTerm_difficulty();
	op = BUTTONS_decode();
	switch(op){
		case OP1:
			difficulty = EASY;
			break;
		case OP2:
			difficulty = MEDIUM;
			break;
		case OP3:
			difficulty = HARD;
			break;
		case OP4:
			difficulty = SAIYAJIN;
		default:
			break;
	}
	return difficulty;
}

void Game_run(){
	uint8 pitIntrStatus = FALSE;
	uint8 score = 0;
	uint8 mole;
	uint32 led;
	uint8 port_led;
	uint8 pin_led;
	uint8 difficulty;

	do{
		difficulty = Game_difficulty();
		led = LED_random();
		port_led = Game_decode_port_led(led);
		pin_led = Game_decode_bit_led(led);
		GPIO_set_pin(port_led, pin_led);

		PIT_clear();
		pitIntrStatus = PIT_getIntrStatus();
		PIT_delay(PIT_0,SYSTEM_CLOCK, difficulty);
		do{
			mole = BUTTONS_decode();
			pitIntrStatus = PIT_getIntrStatus();
		}while(FALSE == pitIntrStatus);
		score = score + POINT;
	}while(led == mole);
	score = score;
}



