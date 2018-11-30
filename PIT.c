/*
 * PIT.c
 *
 *  Created on: Nov 30, 2018
 *      Author: Andy
 */

#include "PIT.h"

static uint32 interruptionFlag = FALSE;

void PIT0_IRQHandler(void){
	/*Modifies the global variable interruptionFlag value */
	interruptionFlag = PIT->CHANNEL[PIT_0].TFLG;
	/*enable the holding interrupt flags*/
	PIT->CHANNEL[PIT_0].TFLG |= PIT_TFLG_TIF_MASK;
	/*read flags*/
	PIT->CHANNEL[PIT_0].TCTRL;
	/*Enables interrupts*/
	PIT->CHANNEL[PIT_0].TCTRL &= ~(PIT_TCTRL_TIE_MASK);
	/*Enables timer*/
	PIT->CHANNEL[PIT_0].TCTRL &= ~(PIT_TCTRL_TEN_MASK);
}

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float period){
	/*Make the time value for the timer*/
	uint32 value = systemClock*period/2;
	PIT->CHANNEL[PIT_0].LDVAL = value;
	/*not enable interrupt*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TIE_MASK;
	/*Not Enables timer*/
	PIT->CHANNEL[PIT_0].TCTRL |= PIT_TCTRL_TEN_MASK;
}


void PIT_clockGating(void){
/*enables PIT clocks*/
	SIM->SCGC6 = PIT_CLOCK_GATING;
	PIT->MCR = 0;
}


uint8 PIT_getIntrStatus(void){
	return interruptionFlag;
}

void PIT_clear(void){
	/*Clears Interruption Flag caused by timer*/
	interruptionFlag = 0;
}
