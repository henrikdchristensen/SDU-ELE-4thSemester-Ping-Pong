/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: ball.h
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

#ifndef _BALL_H
#define _BALL_H

/***************************** Include files *******************************/

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void moveball(void);
/***************************************************************************
 *   Input    : -
 *   Output   : -
 *   Function : Save the balls old coordinates and creates new coordinates 
				for the ball depending on its direction.
 ***************************************************************************/

void spawnball(INT8U new_direction);
/***************************************************************************
 * Input    : New direction of the ball when it is spawned
 * Output   : -
 * Function : Deletes the ball, and resets its coordinates to the middle of
			  the screen. Repaints the ball on the new coordinates and sets
			  the direction to the input direction.
 ***************************************************************************/

/***************************** End Of Module *******************************/

#endif