/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: collision.c
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
#include "draw.h"
#include "ball.h"
#include "bat.h"

/*****************************  Definitions  *******************************/

#define MAXHIGHT		480
#define MAXWIDTH		640

#define SCALEFACTOR		5

#define TOTALESCORE 	100

#define NUMBERSIZE		28

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

extern INT16U x1, x2, x1_old, x2_old, y1, y2, y1_old, y2_old;      // Ball coordinates.
extern INT16U bat1_x1, bat1_x2, bat2_x1, bat2_x2;                  // Bat x coordinates.
extern INT16U bat1_y1, bat1_y2, bat2_y1, bat2_y2;                  // Bat y coordinates.
extern INT16U bat1_y1_old, bat1_y2_old, bat2_y1_old, bat2_y2_old;  // Bat old y coordinates.
extern INT8U direction, speed, ball_dead;

INT8U player1_score, player2_score; // Player scores.

/*****************************   Functions   *******************************/

void collision(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Checks for collisions between the ball and either one of the bats
			  or the top or bottom of the screen. Draws the scores at the top 
			  of the screen and resets them if max score is reached.
 ***************************************************************************/
{
	// Reset the ball if it reaches left side of the screen. Increments the player2 score and changes the scorenumber on screen.
	if(x1 <= 4)
	{
		player2_score++;
		drawnumber(player2_score%10,(MAXWIDTH/2)+(MAXWIDTH/2/2),				0);
		drawnumber(player2_score/10,((MAXWIDTH/2)+(MAXWIDTH/2/2)-NUMBERSIZE),	0);
		
		if (player2_score > TOTALESCORE-1) // Resets both scores if player2 score exeedes max score.
			{
				player1_score = 0;
				player2_score = 0;
				drawnumber(player1_score%10,(MAXWIDTH/2)-(MAXWIDTH/2/2),				0);
				drawnumber(player1_score/10,((MAXWIDTH/2)-(MAXWIDTH/2/2)-NUMBERSIZE),	0);
				drawnumber(player2_score%10,(MAXWIDTH/2)+(MAXWIDTH/2/2),				0);
				drawnumber(player2_score/10,((MAXWIDTH/2)+(MAXWIDTH/2/2)-NUMBERSIZE),	0);
			}
			
		spawnball(6); // Reset the ball with direction 6.
	}
	
	// Reset the ball if it reaches right side of the screen. Increments the player1 score and changes the scorenumber on screen.
	else if(x1 > 624)
	{
		player1_score++;
		drawnumber(player1_score%10,(MAXWIDTH/2)-(MAXWIDTH/2/2),				0);
		drawnumber(player1_score/10,((MAXWIDTH/2)-(MAXWIDTH/2/2)-NUMBERSIZE),	0);
		
		if (player1_score > TOTALESCORE-1)//Resets both scores if player1 score exeedes max score.
			{
				player1_score = 0;
				player2_score = 0;
				drawnumber(player1_score%10,(MAXWIDTH/2)-(MAXWIDTH/2/2),				0);
				drawnumber(player1_score/10,((MAXWIDTH/2)-(MAXWIDTH/2/2)-NUMBERSIZE),	0);
				drawnumber(player2_score%10,(MAXWIDTH/2)+(MAXWIDTH/2/2),				0);
				drawnumber(player2_score/10,((MAXWIDTH/2)+(MAXWIDTH/2/2)-NUMBERSIZE),	0);
			}
		
		spawnball(2); // Resets ball with direction 6.
	}
	
	// If the ball reaches the top of the screen, the direction is changed to the downwards comparable direction.
	if(y1 <= 42)
	{
		if(direction == 1) direction = 4;
		if(direction == 2) direction = 3;
		if(direction == 5) direction = 8;
		if(direction == 6) direction = 7;
	}
	
	// If the ball reaches the bottom of the screen, the direction is changed to the upwards comparable direction.
	else if(y1 >= 467)
	{
		if(direction == 4) direction = 1;
		if(direction == 3) direction = 2;
		if(direction == 8) direction = 5;
		if(direction == 7) direction = 6;
	}
	
	// Checks if the ball collides with the front of player 2s bat (right side of the screen).
	if (x2 >= bat2_x1 && x2 <= (bat2_x1+2))
	{
		// The new direction is decided depending on the part of the bat the ball hits.
		if (y2 >= (bat2_y1) && y2 < (bat2_y1 + 16) ) 
		{
			direction = 1;
		}
		else if (y2 >= (bat2_y1 + 16) && y2 < (bat2_y1 + 36))
		{
			direction = 2;
		}
		else if (y2 >= (bat2_y1 + 36) && y2 < (bat2_y1 + 56))
		{
			direction = 3;
		}
		else if (y2 >= (bat2_y1 + 56) && y2 <= (bat2_y1 + 72))
		{
			direction = 4;
		}
	}
	
	// Redraws the bat if the ball is inside the bat. The ball is only inside the bat if the bat is raised up in the bat after the ball has passed its front.
	else if (x2 >(bat2_x1) && x1 <= bat2_x2+2 && y2 >= (bat2_y1) && y1 <= (bat2_y2+1))
	{
			draw(1, bat2_x1, bat2_x2, bat2_y1, bat2_y2);
	}
	
	// Checks if the ball collides with the front of player 1s bat (left side of the screen).
	else if (x1 <= bat1_x2 && x1 >= bat1_x2-2)
	{
		// The new direction is decided depending on the part of the bat the ball hits.
		if (y2 > (bat1_y1) && y2 < (bat1_y1 + 16) )
		{
			direction = 5;
		}
		else if (y2 >= (bat1_y1 + 16) && y2 < (bat1_y1 + 36))
		{
			direction = 6;
		}
		else if (y2 >= (bat1_y1 + 36) && y2 < (bat1_y1 + 56))
		{
			direction = 7;
		}
		else if (y2 >= (bat1_y1 + 56) && y2 < (bat1_y1 + 72))
		{
			direction = 8;
		}
	}
	
	// Redraws the bat if the ball is inside the bat. The ball is only inside the bat if the bat is raised up in the bat after the ball has passed its front.
	else if (x1 < (bat1_x2) && x2 >= (bat1_x1-2) && y2 >= (bat1_y1) && y1 <= bat1_y2)
	{
			draw(1, bat1_x1, bat1_x2, bat1_y1, bat1_y2);
	}
	
		// Deletes the ball and repaint it on the new coordinates.
		draw(0,x1_old,x2_old,y1_old,y2_old);
		draw(1,x1,x2,y1,y2);
}

/***************************** End Of Module *******************************/
