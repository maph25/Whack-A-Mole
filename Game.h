/*
 * Game.h
 *
 *  Created on: Nov 30, 2018
 *      Author: Andy
 */

#ifndef GAME_H_
#define GAME_H_

#define EASY 2u
#define MEDIUM 1u
#define HARD 0.5F
#define SAIYAJIN 0.25F
#define SYSTEM_CLOCK 21000000

#define POINT 1u
#define LED_ON 0x01
#define LED_OFF 0x00

typedef enum{B1, B2, B3, B4, B5, B6, B7, B8, B9, NULL
}Push_button_t;

uint8 Game_decode_port_led(uint32 random);
uint8 Game_decode_bit_led(uint32 random);
uint8 Game_difficulty();
void Game_run();


#endif /* GAME_H_ */
