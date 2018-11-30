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
#include "Game.h"
#include "Buttons.h"
#include "PIT.h"
#include "Delay.h"

uint8 Game_decode_port(uint32 random){
	uint8 port;
	switch(random){
	case LED1:
		port = GPIO_B;
		break;
	case LED2:
		port = GPIO_B;
		break;
	case LED3:
		port = GPIO_B;
		break;
	case LED4:
		port = GPIO_B;
		break;
	case LED5:
		port = GPIO_B;
		break;
	case LED6:
		return GPIO_C;
		break;
	case LED7:
		port = GPIO_C;
		break;
	case LED8:
		port = GPIO_C;
		break;
	case LED9:
		port = GPIO_A;
		break;
	default:
		break;
	}
	return port;
}

uint8 Game_decode_bit(uint32 random){
	uint8 pin;
	switch(random){
	case LED1:
		pin = BIT2;
		break;
	case LED2:
		pin = BIT3;
		break;
	case LED3:
		pin = BIT10;
		break;
	case LED4:
		pin = BIT11;
		break;
	case LED5:
		pin = BIT20;
		break;
	case LED6:
		pin = BIT10;
		break;
	case LED7:
		pin = BIT11;
		break;
	case LED8:
		pin = BIT4;
		break;
	case LED9:
		pin = BIT0;
		break;
	default:
		break;
	}
	return pin;
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
	uint32 led;
	uint32 port;
	uint8 pin;
	uint8 difficulty;
	/*Stores random led value to beggin game*/

	/*Turn on led*/
	difficulty = Game_difficulty();
	led = LED_random();
	port = Game_decode_port(led);
	pin = Game_decode_bit(led);
	GPIO_set_pin(port, pin);

	PIT_clear();
	pitIntrStatus = PIT_getIntrStatus();
	PIT_delay(PIT_0,SYSTEM_CLOCK,EASY);//2segundos
								   /*Waits for an interruption to occur*/
	do{
	   if((GPIO_set_pin(port, pin) == TRUE )
	   pitIntrStatus = PIT_getIntrStatus();
	}while(FALSE == pitIntrStatus);
}
