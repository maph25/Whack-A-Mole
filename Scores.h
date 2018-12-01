/*
 * Scores.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Andy
 */

#ifndef SCORES_H_
#define SCORES_H_

#include "Bits.h"

#define CENTENNIAL_MASK 100u
#define DECIMAL_MASK 10u
#define HEX_ADDER 0x30
#define MULT1 100u
#define MULT2 10u
/*BCD score*/
uint8 Scores_decimal(uint8 data);

#endif /* SCORES_H_ */
