/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: swkeys.c
 *
 * PROJECT....: Pong
 *
 * DESCRIPTION: | SW1 | Grøn | Gul | Rød | SW2 |
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
#include "emp_type.h"
#include "tm4c123gh6pm.h"
#include "swkeys.h"

/*****************************  Definitions  *******************************/
// Port F:
#define		sw1		0x10
#define		sw2		0x01

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void swkeys_init(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initialize sw1 key and sw2 key.
 ***************************************************************************/
{
	SYSCTL_RCGC2_R   |=  SYSCTL_RCGC2_GPIOF;  // Set port GPIO active.
	
	GPIO_PORTF_LOCK_R = 0x4C4F434B;     // Unlock the CR register.
	GPIO_PORTF_CR_R   = 0xFF;           // Enable overwrite of PUR to FP0.

	GPIO_PORTF_DEN_R |=  (sw1 | sw2);   // Set port GPIO pins to digital functions.
	GPIO_PORTF_DIR_R &=  ~(sw1 | sw2);  // Set direction.
	GPIO_PORTF_PUR_R |=	(sw1 | sw2);    // Pull-up is on board.
}

INT8U swkeys1_read(INT8U *pSw1)
/***************************************************************************
 * Input    : - 
 * Output   : If button have been pressed or not.
 * Function : Check button sw1.
 ***************************************************************************/
{
	static INT8U OldSw1;

	INT8U Result = 0;
	*pSw1 = 0;

	if ((GPIO_PORTF_DATA_R & sw1) == 0)
	{ // Button active on low:
		if (OldSw1 != 1)
		{ // Button not same as before:
			OldSw1 = 1;
			*pSw1 = 1;
			Result = 1;
		}
	}
	else
	{
		if (OldSw1 != 0)
		{ // Button still pressed:
			OldSw1 = 0;
			*pSw1 = 0;
			Result = 1;
		}
	}
	return Result;
}

// Not used:
INT8U swkeys2_read(INT8U *pSw2)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : -
 ***************************************************************************/
{
	static INT8U OldSw2 = 0;
	INT8U Result = 0;

	if ((GPIO_PORTF_DATA_R & sw2) == 0)
	{ // Button active on low:
		if (OldSw2 == 0)
		{
			OldSw2  =  1;
			Result  =  1;
		}
	}
	else
	{
		OldSw2  =  0;
	}
	*pSw2 = OldSw2;

	return Result;
}

/***************************** End Of Module *******************************/