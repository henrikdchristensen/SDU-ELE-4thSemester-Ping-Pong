/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: adc.c
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
#include "adc.h"

/*****************************  Definitions  *******************************/

#define scale	11  				// Set scalefactor for ADC output (4095 / scalefactor = value).
#define PORT	SYSCTL_RCGC2_GPIOE  // Set Port.
#define PIN		0x00000030          // Set Pin.
#define AIN		0x00000098          // Set AIN

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void adc_init(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initialize the ADC.
 ***************************************************************************/
{
	SYSCTL_RCGC0_R |= SYSCTL_RCGC0_ADC0;  // Clock gating for ADC.
	SYSCTL_RCGC2_R |= PORT;  			  // Enable port.

	GPIO_PORTE_DIR_R   &= ~(PIN);  // Set direction to analog (not digital).
	GPIO_PORTE_AFSEL_R &= ~(PIN);  // Disable alternative function for PE4-5.
	GPIO_PORTE_AMSEL_R |= PIN;     // Enable analog function for PE4-5.

	SYSCTL_RCGC0_R |= SYSCTL_RCGC0_ADC0SPD_500K;  // Sample rate speed.

	ADC0_ACTSS_R  &= ~(0x00000001);  // Make sure it's not running, disable sample sequence 0.
	ADC0_SSPRI_R  =  0x00003210;  	 // Top priority for sample sequencer 0.
	ADC0_EMUX_R	  =	 (ADC0_EMUX_R & ~0x0000000F) | 0x00000000;  // Choice ADC event Starter, chosen is by command.
	ADC0_SSMUX0_R =	 AIN;  		  // Input mapping to sequence sample bit-field register, analog input 9 and 8 to PE4 and PE5.
	ADC0_SSCTL0_R =	 0x00000060;  // Sample sequence control.
	ADC0_ACTSS_R  |= 0x00000001;
}

INT16U adc_read(INT16U *pdata0, INT16U *pdata1)
/***************************************************************************
 * Input    : Take two integers as inputs.
 * Output   : If any changes output is 1.
 * Function : pdata0 store changes and pdata1 store changes when push.
 ***************************************************************************/
{
	INT16U Result = 0;

	ADC0_PSSI_R	|= 0x00000001;  // Start conversion bit (very importing!).

	while((ADC0_RIS_R & 0x00000001) == 0)
	{
	}

	// Data register:
	*pdata0 = ADC0_SSFIFO0_R / scale;
	*pdata1	= ADC0_SSFIFO0_R / scale;
	
	Result = 1;
	
	return (Result);
}

/***************************** End Of Module *******************************/
