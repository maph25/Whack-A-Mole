/*
 * LED.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Andy
 */

#ifndef LED_H_
#define LED_H_

#define LED1 	 0x01
#define LED2	 0x02
#define LED3	 0x03
#define LED4	 0x04
#define LED5	 0x05
#define LED6	 0x06
#define LED7	 0x07
#define LED8	 0x08
#define LED9	 0x09
#define LED_NULL 0xFF

void LED_init();
uint32 LED_random ();


#endif /* LED_H_ */
