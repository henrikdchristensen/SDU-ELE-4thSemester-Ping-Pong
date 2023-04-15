/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: drawnumber.h
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

#ifndef _DRAWNUMBER_H
#define _DRAWNUMBER_H

/***************************** Include files *******************************/

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void drawnumber(INT8U number, INT16U x1, INT16U y1);
/***************************************************************************
 * Input    : number, x1, y1
 * Output   : -
 * Function : Draw a number (1,2,3,4,5,6,7,8,9,0) with x and y coordinates,
 *  		  at the left upper corner of the digital segment. If the number-input
			  is 11, the function will clear the digital segment.
 ***************************************************************************/

/***************************** End Of Module *******************************/

#endif