/**
 * @file    Game.c
 * @brief   Application entry point.
 */
#include "Flex.h"
#include "BUTTONS.h"
#include "LED.h"
#include "UART.h"
#include "MK64F12.h"

#define SYSTEM_CLOCK 21000000


int main(void) {
	/*Initializations*/
	Flex_init();
	BUTTONS_init();
	LED_init();
	UART_init(UART_0, SYSTEM_CLOCK, BD_115200);

    while(1) {

    }
    return 0 ;
}
