/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: drawnumber.c
 *
 * PROJECT....: Pong
 *
 * DESCRIPTION: Uses the draw-function from draw.c to draw a digital segment.
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
#include "draw.h"
#include "ball.h"
#include "midline.h"

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void drawnumber(INT8U number, INT16U x1, INT16U y1)
/***************************************************************************
 * Input    : number, x1, y1
 * Output   : -
 * Function : Draw a number (1,2,3,4,5,6,7,8,9,0) with x and y coordinates,
 *  		  at the left upper corner of the digital segment. If the number-input
			  is 11, the function will clear the digital segment.
 ***************************************************************************/
{
	// Clear all digital segment A,B,C,D,E,F,G with the draw-function:
	draw(0,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
	draw(0,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
	draw(0,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
	draw(0,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
	draw(0,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
	draw(0,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
	draw(0,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
	
	// Draw the number with a switch-case depending on the number-input:
	switch (number) {
		case 1:
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.

			break;
		
		case 2:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment C.
			draw(1,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
					break;
		
		case 3:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 4:
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 5:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 6:
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(1,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 7:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			break;
		
		case 8:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(1,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 9:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(1,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
		
		case 0:
			draw(1,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(1,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(1,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(1,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(1,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
			draw(1,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			break;
		
		case 11:
			// Case 11, clear all digital segment A, B, C, D, E, F, G with the draw-function:
			draw(0,(x1+8) ,(x1+20),(y1+2) ,(y1+5));   // Digital segment A.
			draw(0,(x1+21),(x1+26),(y1+2) ,(y1+17));  // Digital segment B.
			draw(0,(x1+21),(x1+26),(y1+19),(y1+34));  // Digital segment C.
			draw(0,(x1+8) ,(x1+20),(y1+31),(y1+34));  // Digital segment D.
			draw(0,(x1+2) ,(x1+7) ,(y1+19),(y1+34));  // Digital segment E.
			draw(0,(x1+2) ,(x1+7) ,(y1+2) ,(y1+17));  // Digital segment F.
			draw(0,(x1+8) ,(x1+20),(y1+16),(y1+20));  // Digital segment G.
			break;
	}
}

/***************************** End Of Module *******************************/
