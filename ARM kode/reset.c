/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: reset.c
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
#include "emp_type.h"
#include "tm4c123gh6pm.h"
#include "swkeys.h"
#include "draw.h"
#include "ball.h"
#include "midline.h"
#include "drawnumber.h"
#include "collision.h"
#include "timer.h"
#include "bat.h"

/*****************************  Definitions  *******************************/

// Screen dimensions:
#define MAXHIGHT		480			
#define MAXWIDTH		640

#define NUMBERSIZE		28    // Size of numbers (from drawnumber function).

#define COUNTDOWNTIME	1000  // Countdowntime after reset in ms.

#define OFFSET			(-(NUMBERSIZE/2))  // Calculated offset.

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

// Getting bat coordinates to spawn it:
extern INT16U bat1_y1, bat1_y2, bat2_y1, bat2_y2;
extern INT16U bat1_y1_old, bat1_y2_old, bat2_y1_old, bat2_y2_old, bat1_x1, bat1_x2, bat2_x1, bat2_x2;

// Getting player scores to reset them:
extern INT8U player1_score, player2_score;

/*****************************   Functions   *******************************/

void reset(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Reset the boundaries, score, ball and countdown to new start.
 ***************************************************************************/
{
	INT8U pSw1 	= 0;
	INT16U ms	= 0;

	if (swkeys1_read(&pSw1))
	{	// A button is pressed:
		if (pSw1 == 1)
		{ // If SW1 is pressed:
			
			// Draw boundaries:
			draw(0,0,640,0,480);
			draw(1,0,640,37,40);
			draw(1,0,640,478,480);

			// Reset and draws the score:
			player1_score = 0;
			drawnumber(player1_score%10,(MAXWIDTH/2)+(MAXWIDTH/2/2),				0);
			drawnumber(player1_score/10,((MAXWIDTH/2)+(MAXWIDTH/2/2)-NUMBERSIZE),	0);
			player2_score = 0;
			drawnumber(player2_score%10,(MAXWIDTH/2)-(MAXWIDTH/2/2),				0);
			drawnumber(player2_score/10,((MAXWIDTH/2)-(MAXWIDTH/2/2)-NUMBERSIZE),	0);

			// Draw first countdown number:
			drawnumber(3,MAXWIDTH/2+OFFSET,MAXHIGHT/2);
			ms = 0;
			
			// Time control loop:
			while(ms <= COUNTDOWNTIME)
			{	
				if (timer_read())
				{	// If 1 ms have elapse:
					ms ++;
				}
			}
			
			ms = 0;
			
			// Draw second countdown number:
			drawnumber(2,MAXWIDTH/2+OFFSET,MAXHIGHT/2);
			
			while(ms <= COUNTDOWNTIME)
			{
				if (timer_read())
				{
					ms ++;
				}
			}
			
			ms = 0;
			
			// Draw last countdown number:
			drawnumber(1,MAXWIDTH/2+OFFSET,MAXHIGHT/2);
			
			while(ms <= COUNTDOWNTIME)
			{
				if (timer_read())
				{
					ms ++;
				}
			}
			
			ms = 0;
			
			// Removes the drawn number:
			drawnumber(11,MAXWIDTH/2+OFFSET,MAXHIGHT/2);
			
			// Initialize the net in the middle:
			midline_init();
	
			// Reset and draws the score (minor bug: if it only resets before the wait time, scores will start at 2) 
			player1_score = 0;
			drawnumber(player1_score%10,(MAXWIDTH/2)+(MAXWIDTH/2/2),				0);
			drawnumber(player1_score/10,((MAXWIDTH/2)+(MAXWIDTH/2/2)-NUMBERSIZE),	0);
			player2_score = 0;
			drawnumber(player2_score%10,(MAXWIDTH/2)-(MAXWIDTH/2/2),				0);
			drawnumber(player2_score/10,((MAXWIDTH/2)-(MAXWIDTH/2/2)-NUMBERSIZE),	0);
			
			// Draw the bats:
			draw(1, bat2_x1, bat2_x2, bat2_y1, bat2_y2);
			draw(1, bat1_x1, bat1_x2, bat1_y1, bat1_y2);
	
			// Spawn the ball:
			spawnball(2);
		}
	}
}

/****************************** End Of Module *******************************/