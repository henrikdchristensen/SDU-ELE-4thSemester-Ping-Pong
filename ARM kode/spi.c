/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: spi.c
 *
 * PROJECT....: Pong
 *
 * DESCRIPTION:
 *
 * Change Log:
 ***************************************************************************
 * Date    	Id			Change
 * YYMMDD
 * ------------------------------------
 * 150505  	GRP. 6    	Module created.
 ***************************************************************************/

/***************************** Include files *******************************/

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "spi.h"

/*****************************  Definitions  *******************************/

#define	OSC	16000000
#define BR	8000000		// [32000;8000000] watch out for tight sending loops.

#define SSICLK ((OSC /(BR * 2)) - 1)  // Calculate SPI clock. 2 for highest speed.

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void spi_init(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Setup spi.
 ***************************************************************************/
{
	// 1. 32 bit registers
	// Turn on the SSI module 2
	SYSCTL_RCGCSSI_R	|= 0x00000004;		// Set SSI module 2 (port b) in Run mode side 345.

	// 2.
	// Set port b for SSI
	SYSCTL_RCGCGPIO_R	|= 0x00000002;		// Set run mode clock gating control port b side 339.

	// 3.
	GPIO_PORTB_AFSEL_R	|= 0x000000F0;		// Enable alternative functions for Port b side 670.

	// 4
	GPIO_PORTB_PCTL_R	|= 0x22220000;		// PWCn (is 4-bit for each pin) port b, side 689, side 651.

	// 5 port setup
	// 5.a
	GPIO_PORTB_DEN_R	|= 0x000000F0;		// Set pin 4, 5, 6, 7 to digital.

	// SPI setup
	// 1 SSE bit
	SSI2_CR1_R			&= ~(0x00000002);	// Clear the SSE bit.

	// SPI setup
	// 2 Master or slave
	SSI2_CR1_R			= 0x00000000;		// Clear the register making it the spi master.

	// 3 CLK source
	SSI2_CC_R			= 0x00000000;		// Choice system CLK as baud clk source.

	// 4 Prescale
	// SSInCLK = SysClk / (CPSDVSR * (1 + SCR))
	SSI2_CPSR_R			= 0x00000002;		// CPSDVSR have to be a even number for max clk rate.

	// 5 a
	// SCR
	SSI2_CR0_R			= (((SSICLK & 0xFF) << 8) | 0x09);	// Set to 1 which give a SCLK to 10kHz.

	// SPI start
	SSI2_CR1_R			|= (0x02);	// Set the SSE bit.
}

void spi_write(INT16U C)
/***************************************************************************
 * Input    : INT16U variable.
 * Output   : -
 * Function : Write out one variable at a time.
 ***************************************************************************/
{
	SSI2_DR_R 			=	C;
}

void spi_transfer(INT32U data)
/***************************************************************************
 * Input    : INT32U variable.
 * Output   : -
 * Function : Write out one larger variable (write out two times) at a time.
 ***************************************************************************/
{
	SSI2_DR_R = ((data >> 10) & 0xFFFF);
	SSI2_DR_R = ((data) & 0xFFFF);
}

/***************************** End Of Module *******************************/