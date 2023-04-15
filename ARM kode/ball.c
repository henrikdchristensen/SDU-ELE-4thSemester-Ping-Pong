/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: ball.c
 *
 * PROJECT....: Pong
 *
 * DESCRIPTION:
 * Sketch of the ball with coordinates on the corners:
 *	x1,y1____x2,y1
 *		|	 |
 *		|____|
 *	x1,y2    x2,y2
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
#include "draw.h"
#include "collision.h"

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

INT16U x1, x2, x1_old, x2_old, y1, y2, y1_old, y2_old;  // Ball coordinates.
INT8U direction, ball_dead;  							// Ball direction.

/*****************************   Functions   *******************************/

void spawnball(INT8U new_direction)
/***************************************************************************
 * Input    : New direction of the ball when it is spawned.
 * Output   : -
 * Function : Deletes the ball, and resets its coordinates to the middle of
			  the screen. Repaints the ball on the new coordinates and sets
			  the direction to the input direction.
 ***************************************************************************/
{
	draw(0,x1,x2,y1,y2);
	x1 = 315;
	x2 = 327;
	y1 = 236;
	y2 = 245;

	draw(1,x1,x2,y1,y2);
	direction = new_direction;
	ball_dead = 0;
}

void moveball(void)
/***************************************************************************
 *   Input    : -
 *   Output   : -
 *   Function : Save the balls old coordinates and creates new coordinates 
				for the ball depending on its direction.
 ***************************************************************************/
{
	// Saves old coordinates:
	x1_old = x1;
	x2_old = x2;
	y1_old = y1;
	y2_old = y2;

	// Creates new coordinates depending on direction:
	switch(direction)
	{
	case 1:
		x1 = x1-2;
		x2 = x2-2;
		y1 = y1-2;
		y2 = y2-2;
		break;

	case 2:
		x1 = x1-2;
		x2 = x2-2;
		y1 = y1-1;
		y2 = y2-1;
		break;

	case 3:
		x1 = x1-2;
		x2 = x2-2;
		y1 = y1+1;
		y2 = y2+1;
		break;

	case 4:
		x1 = x1-2;
		x2 = x2-2;
		y1 = y1+2;
		y2 = y2+2;
		break;

	case 5:
		x1 = x1+2;
		x2 = x2+2;
		y1 = y1-2;
		y2 = y2-2;
		break;

	case 6:
		x1 = x1+2;
		x2 = x2+2;
		y1 = y1-1;
		y2 = y2-1;
		break;

	case 7:
		x1 = x1+2;
		x2 = x2+2;
		y1 = y1+1;
		y2 = y2+1;
		break;

	case 8:
		x1 = x1+2;
		x2 = x2+2;
		y1 = y1+2;
		y2 = y2+2;
		break;
	}
}

/***************************** End Of Module *******************************/
