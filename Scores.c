/*
 * Scores.c
 *
 *  Created on: Nov 19, 2018
 *      Author: Andy
 */
#include "Scores.h"
#include "Bits.h"

uint8 Scores_decimal(uint8 data){
	uint8 score[3];
	uint8 temp_decimal;
	uint8 temp_unit;
	score[2] = data / CENTENNIAL_MASK;
	temp_decimal = data - (score[2] * MULT1);
	score[1] = temp_decimal / DECIMAL_MASK;
	temp_unit = temp_decimal -(score[1] * MULT2);
	score[0] = temp_unit;
	score[2] = score[2] + HEX_ADDER;
	score[1] = score[1] + HEX_ADDER;
	score[0] = score[0] + HEX_ADDER;

	return(score[3]);

}
