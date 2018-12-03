/**
 * @file    Game.c
 * @brief   Application entry point.
 */
#include "Flex.h"
#include "BUTTONS.h"
#include "Game.h"
#include "TeraTerm.h"
#include "LED.h"
#include "NVIC.h"
#include "PIT.h"
#include "UART.h"
#include "MK64F12.h"

#define SYSTEM_CLOCK 21000000


int main(void) {
	uint8 option;
	/*Initializations*/
	Flex_init();
	BUTTONS_init();
	LED_init();
	UART_init(UART_0, SYSTEM_CLOCK, BD_115200);
	PIT_clockGating();
	NVIC_enableInterruptAndPriotity(PIT_CH0_IRQ, PRIORITY_10);
	EnableInterrupts;

    while(1) {
    	TeraTerm_menu();
    	option = BUTTONS_decode();
    	if(option == OP1){
    		TeraTerm_difficulty();
    		Game_run();
    	}

    }
    return 0 ;
}
