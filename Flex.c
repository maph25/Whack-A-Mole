/**
	\file
	\brief
		This is the starter file of FlexTimer.
		In this file the FlexTimer is configured in overflow mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	7/09/2014
	\todo
	    Add configuration structures.
 */


#include "Flex.h"
#include "MK64F12.h"

void FTM0_ISR()
{
	FTM0->SC &= ~FLEX_TIMER_TOF;
	GPIOD->PDOR ^= 0xFF;
}

void FlexTimer_Init()
{
	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= FLEX_TIMER_0_CLOCK_GATING;
	/**When write protection is enabled (WPDIS = 0), write protected bits cannot be written.
	 * When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
	FTM0->MODE |= FLEX_TIMER_WPDIS;
	/**This field is write protected. It can be written only when MODE[WPDIS] = 1.*/
	/**
	 * 0 Only the TPM-compatible registers (first set of registers) can be used without any restriction. Do not
	 * use the FTM-specific registers.
	 * 1 All registers including the FTM-specific registers (second set of registers) are available for use with no restrictions.*/
	FTM0->MODE &= ~FLEX_TIMER_FTMEN;
	//FTM0_MODE |= FLEX_TIMER_FTMEN;
	/**Selects the FTM behavior in BDM mode.In this case in functional mode*/
	FTM0->CONF |= FTM_CONF_BDMMODE(3);

	/**Assign modulo register with a predefined value*/
	FTM0->MOD = 0x02;
	/**Configure FlexTimer in output compare in toggle mode*/
	FTM0->CONTROLS[0].CnSC = FLEX_TIMER_MSA | FLEX_TIMER_ELSA;
	/**Assign channel value register with a predefined value*/
	FTM0->CONTROLS[0].CnV = 0x00;
	/**Select clock source and prescaler*/
	FTM0->SC |= FLEX_TIMER_CLKS_1|FLEX_TIMER_PS_1;
}
