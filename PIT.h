/*
 * PIT.h
 *
 *  Created on: 16/08/2017
 *      Author: jlpe
 */

#ifndef PIT_H_
#define PIT_H_

#include "MK64F12.h"
#include "Bits.h"

/*! This enumerated constant are used to select the PIT to be used*/
typedef enum {PIT_0,PIT_1,PIT_2,PIT_3} PIT_Timer_t;

/** Constant that represent the clock enable for GPIO A */
#define PIT_CLOCK_GATING 0x00800000
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function configure the PIT to generate a delay base on the system clock.
 	 Internally it configures the clock gating and enables the PIT module.
 	 It is important to note that this strictly is not device driver since everything is
 	 contained in a single function, but in general you have to avoid this practices, this only
 	 for the propose of the homework

 	 \param[in]  portName Port to be configured.
 	 \return void
 */

void PIT0_IRQHandler(void);

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float periodo);

void PIT_clockGating(void);

uint8 PIT_getIntrStatus(void);

void PIT_clear(void);


#endif /* PIT_H_ */
