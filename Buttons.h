/*
 * Buttons.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Andy
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/*Values for push buttons in the decoding function*/
#define B1   0x01
#define B2 	 0x02
#define B3 	 0x03
#define B4 	 0x04
#define B5 	 0x05
#define B6 	 0x06
#define B7	 0x07
#define B8 	 0x08
#define B9	 0x09
#define BUTTONS_NULL 0xFF

/*Push buttons configuration*/
void BUTTONS_init();
/*Decode which button created the interruption*/
uint8 BUTTONS_decode();


#endif /* BUTTONS_H_ */
