/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: draw.c
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
#include "timer.h"

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void draw(INT8U databit, INT16U x1, INT16U x2, INT16U y1, INT16U y2)
/***************************************************************************
 * Input    : databit (1=draw pixel/0=not draw pixel), x1, x2, y1, x2
 * Output   : -
 * Function : Drawing a square with the upper left corner at x1,y1 and the 
 * 			  lower right corner at x2,y2. Uses the spi-transfer-function
			  to send the data via the SPI.
 ***************************************************************************/
{
	INT16U x_low, y_low;
	for (x_low = x1 ; x_low <= x2-2 ; x_low++)    // A for-loop from x1 to x2 (-2, because of 2 pixel error on the screen).
	{
		for (y_low = y1 ; y_low <= y2 ; y_low++)  // A for-loop from y1 to y2.
		{
			spi_transfer((((640 * (y_low - 1) + x_low)) << 1 ) | databit);  // Send 19bit address bit and 1 data bit to the FPGA, for every pixel on the screen.
		}
	}
}

/***************************** End Of Module *******************************/
