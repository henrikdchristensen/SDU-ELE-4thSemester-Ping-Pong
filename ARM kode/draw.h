/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: draw.h
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

#ifndef _DRAW_H
#define _DRAW_H

/***************************** Include files *******************************/

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void draw(INT8U databit, INT16U x1, INT16U x2, INT16U y1, INT16U y2);
/***************************************************************************
 * Input    : databit (1=draw pixel/0=not draw pixel), x1, x2, y1, x2
 * Output   : -
 * Function : Drawing a square with the upper left corner at x1,y1 and the 
 * 			  lower right corner at x2,y2. Uses the spi-transfer-function
			  to send the data via the SPI.
 ***************************************************************************/

/***************************** End Of Module *******************************/

#endif