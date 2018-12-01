/*
 * Buttons.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/*Values for push buttons in the decoding function*/
#define OP1  0x0A
#define OP2	 0x0B
#define OP3	 0x0C
#define OP4	 0x0D


/*Push buttons configuration*/
void BUTTONS_init();
/*Decode which button created the interruption*/
uint8 BUTTONS_decode();


#endif /* BUTTONS_H_ */
