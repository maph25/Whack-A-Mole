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

#define LED_ON 0x01
#define LED_OFF 0x00

uint8 Game_decode_port(uint32 random);
uint8 Game_decode_bit(uint32 random);
void Game_run();


#endif /* GAME_H_ */
