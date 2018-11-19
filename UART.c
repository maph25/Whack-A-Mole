/*!
 *  @file UART.c
 *
 *  @Date on: Mar 27, 2018
 *  @author MartinR
 */

#include "UART.h"
#include "MK64F12.h"

UART_MailBoxType UART0_MailBox; /** Structure to receive the data from the UART**/

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This is the interrupt services routing (ISR).
 	 \param[in]  void.
 	 \return void
 */
void UART0_RX_TX_IRQHandler(void)
{
	while(!(UART0->S1 & UART_S1_RDRF_MASK));
	UART0_MailBox.flag = TRUE;
	UART0_MailBox.mailBox = UART0->D;

}

uint8 UART_mailbox_return(){
	uint8 getMail;
	getMail = UART0_MailBox.mailBox;
	return getMail;
}

uint8 UART_flag_return(){
	uint8 getFlag;
	getFlag = UART0_MailBox.flag;
	return getFlag;
}


void UART_init(UART_ChannelType uartChannel, uint32 system_clock, UART_BaudRateType baudRate)
{
	gpio_pin_control_register_t config = GPIO_MUX3;
	GPIO_clock_gating(GPIO_B);
	GPIO_pin_control_register(GPIO_B, BIT16, &config);
	GPIO_pin_control_register(GPIO_B, BIT17, &config);
	uint16 baud_rate;
	uint8 temp;
	baud_rate = system_clock/(baudRate*UART_MULT);
	temp = (system_clock/(baudRate*UART_MULT)-baud_rate)*UART_MULT_2;
	switch(uartChannel)
	{
	case UART_0:
		SIM->SCGC4 |= SIM_SCGC4_UART0_MASK; /*Enables the clock*/

		UART0->C2 &= ~(UART_C2_TE_MASK); /*Disables both transmitter and receiver*/
		UART0->C2 &= ~(UART_C2_RE_MASK);
		UART0->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART0->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART0->C4 = temp & UART_C4_BRFA_MASK;
		UART0->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART0->C2 |= UART_C2_RE_MASK;
		break;
	case UART_1:
		SIM->SCGC4 |= SIM_SCGC4_UART1_MASK; /* Enables the clock module**/
		UART1->C2 &= ~(UART_C2_TE_MASK); /*Disables both transmitter and receiver*/
		UART1->C2 &= ~(UART_C2_RE_MASK);
		UART1->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART1->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART1->C4 = temp & UART_C4_BRFA_MASK;
		UART1->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART1->C2 |= UART_C2_RE_MASK;
		break;
	case UART_2:
		SIM->SCGC4 |= SIM_SCGC4_UART2_MASK; /*Enables the clock module**/
		UART2->C2 &= ~(UART_C2_RE_MASK);
		UART2->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART2->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART2->C4 = temp & UART_C4_BRFA_MASK;
		UART2->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART2->C2 |= UART_C2_RE_MASK;
		break;
	case UART_3:
		SIM->SCGC4 |= SIM_SCGC4_UART3_MASK; /*Enables the clock module**/
		UART3->C2 &= ~(UART_C2_RE_MASK);
		UART3->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART3->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART3->C4 = temp & UART_C4_BRFA_MASK;
		UART3->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART3->C2 |= UART_C2_RE_MASK;
		break;
	case UART_4:
		SIM->SCGC1 |= SIM_SCGC1_UART4_MASK; /** Enables the clock module**/
		UART4->C2 &= ~(UART_C2_RE_MASK);
		UART4->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART4->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART4->C4 = temp & UART_C4_BRFA_MASK;
		UART4->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART4->C2 |= UART_C2_RE_MASK;
		break;
	case UART_5:
		SIM->SCGC1 |= SIM_SCGC1_UART5_MASK; /** Enables the clock module**/
		UART5->C2 &= ~(UART_C2_RE_MASK);
		UART5->BDH = (baud_rate & UART_BDH_SBR_MASK)>>UART_SHIFT;
		UART5->BDL = (baud_rate & UART_BDL_SBR_MASK);
		UART5->C4 = temp & UART_C4_BRFA_MASK;
		UART5->C2 |= UART_C2_TE_MASK; /*Enables both transmitter and receiver*/
		UART5->C2 |= UART_C2_RE_MASK;
		break;
	default:
		break;
	}
}


void UART_interrupt_enable(UART_ChannelType uartChannel)
{
	switch(uartChannel) /** Selects the UARTn**/
	{
	case UART_0:
		UART0->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	case UART_1:
		UART1->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	case UART_2:
		UART2->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	case UART_3:
		UART3->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	case UART_4:
		UART4->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	case UART_5:
		UART5->C2 |= UART_C2_RIE_MASK; /** Enables the interruption on Rx**/
		break;
	default:
		break;
	}
}


void UART_put_char(UART_ChannelType uartChannel, uint8 character)
{
	switch(uartChannel) /** Selects the UARTn**/
	{
	case UART_0:
		UART0->S1; /** Reads the S1 register to prepare the Transmission**/
		while(!(UART0->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART0->D = character; /** Sends the datq**/
		break;
	case UART_1:
		while(!(UART1->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART1->D = character; /** Sends the datq**/
		break;
	case UART_2:
		while(!(UART2->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART2->D = character; /** Sends the datq**/
		break;
	case UART_3:
		while(!(UART3->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART3->D = character; /** Sends the datq**/
		break;
	case UART_4:
		while(!(UART4->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART4->D = character; /** Sends the datq**/
		break;
	case UART_5:
		while(!(UART5->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		UART5->D = character; /** Sends the datq**/
		break;
	}
}


void UART_put_string(UART_ChannelType uartChannel, sint8* string)
{
	switch(uartChannel)
	{
	case UART_0:
		while(!(UART0->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string) /** Keep sending characters until NULL**/
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	case UART_1:
		while(!(UART1->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string)
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	case UART_2:
		while(!(UART2->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string)
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	case UART_3:
		while(!(UART3->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string)
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	case UART_4:
		while(!(UART4->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string)
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	case UART_5:
		while(!(UART5->S1 & UART_S1_TC_MASK)); /** Waits for the current transmission to end**/
		while(*string)
		{
			UART_put_char(uartChannel, *string++); /** send the current character and then point to the next**/
		}
		break;
	default:
		break;
	}
}
