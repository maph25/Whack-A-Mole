/*
 * TeraTerm.c
 *
 *  Created on: Nov 24, 2018
 *      Author: Andy
 */
#include "UART.h"

/*Print menu*/
void TeraTerm_menu(){
	UART_put_string(UART_0,"\033[2J");
	UART_put_string(UART_0,"\033[0;37;44m"); /*Text in white and background in blue */
	UART_put_string(UART_0,"\033[8;5H");X and Y position
	UART_put_string(UART_0, "Wack-A-Mole by Andrea Perez /r"); /*Prints greetings*/
	UART_put_string(UART_0,"\033[8;10H");/*X and Y position*/
	UART_put_string(UART_0, "1. Start Game/r"); /*Prints menu option 1*/
	UART_put_string(UART_0,"\033[8;10H");/*X and Y position*/
	UART_put_string(UART_0, "2. High scores/r"); /*Prints menu option 2*/
}

void TeraTerm_difficulty(){
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;37;44m"); /*Text in white and background in blue */
	UART_put_string(UART_0,"\033[8;5H");/*X and Y position*/
	UART_put_string(UART_0,"Choose game difficulty \r"); /*Prints greetings*/
	UART_put_string(UART_0,"\033[8;8H");/*X and Y position*/
	UART_put_string(UART_0,"1.- Easy \r"); /*OP1*/
	UART_put_string(UART_0,"\033[8;8H");/*X and Y position*/
	UART_put_string(UART_0,"2.- Medium \r"); /*OP2*/
	UART_put_string(UART_0,"\033[8;8H");/*X and Y position*/
	UART_put_string(UART_0,"3.- Hard \r"); /*OP3*/
	UART_put_string(UART_0,"\033[8;8H");/*X and Y position*/
	UART_put_string(UART_0,"4.- Saiyajin \r"); /*OP4*/
}
