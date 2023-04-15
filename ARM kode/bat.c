/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: bat.c
 *
 * PROJECT....: Pong
 *
 * DESCRIPTION:
 * Bat coordinates
 *	x1,y1 ___ x2,y1 
 *		 |	 |
 *		 |	 |
 *		 |	 |
 *		 |	 |
 *		 |	 |
 *       |	 |
 *		 |___|
 *	x1,y2	  x2,y2
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
#include "bat.h"
#include "draw.h"

/*****************************  Definitions  *******************************/

#define BAT_WIDTH	 12	  // Width of the bats.
#define SCREEN_WIDTH 640  // Width of the screen.					
#define SCREEN_HIGHT 477  // Hight of the screen.

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

INT16U bat1_y1, bat1_y2, bat2_y1, bat2_y2;  // Bat y coordinates.

INT16U bat1_y1_old, bat1_y2_old, bat2_y1_old, bat2_y2_old;  // Save old adc value.
INT16U adc_value_old1, adc_value_old2 = 500; 			    // Adc_value (0-372)

INT16U	bat1_x1	= 20;					 // bat1 x1
INT16U	bat1_x2	= 20 + BAT_WIDTH;		 // bat1 x2
INT16U	bat2_x1	= 640 - 30;				 // bat2 x1
INT16U	bat2_x2	= 640 - 30 + BAT_WIDTH;  // bat2 x2

/*****************************   Functions   *******************************/

void bat(INT16U adc_value, INT8U player)
/***************************************************************************
 *   Input    : -
 *   Output   : -
 *   Function : Move the bat up and down. use the draw function to create the bat.
				Takes in the adc value and make the bat after that.
 ***************************************************************************/
{
		 // Player 1:
		if (player == 1)
		{
			if (adc_value != adc_value_old1)  // Check for bat movement.
			{
				// Save bat coordinates for future comparison:
				bat1_y1_old = bat1_y1;									
				bat1_y2_old = bat1_y2;

				bat1_y1 = SCREEN_HIGHT - (adc_value + 64);  // y1.
				bat1_y2	= SCREEN_HIGHT - (adc_value);		// y2.

				if (bat1_y1 > bat1_y1_old && bat1_y1_old > 101 )		 // Bat is moving downwards and far enough from top of the screen.
				{
					draw(0, bat1_x1, bat1_x2, bat1_y1_old-60, bat1_y1);  // Delete the old part of the bat and 60 pixels above.
					draw(1, bat1_x1, bat1_x2, bat1_y2_old, bat1_y2);	 // Draws new part of the bat.
				}
				else if (bat1_y1 > bat1_y1_old)							 // Bat moving downwards, close to top edge.
				{
					draw(0, bat1_x1, bat1_x2, 41, bat1_y1);				 // Deletes bat from top of the screen to the new bat placement.
					draw(1, bat1_x1, bat1_x2, bat1_y2_old, bat1_y2);	 // Draws new part of the bat.
				}

				if(bat1_y1 < bat1_y1_old && bat1_y2_old < 417 )			 // Bat is moving upwards and far from bottom of the screen.
				{
					draw(0, bat1_x1, bat1_x2, bat1_y2, bat1_y2_old+60);	 // Deletes old part of the bat and 60 pixels below.
					draw(1, bat1_x1, bat1_x2, bat1_y1, bat1_y1_old);	 // Draws new part of the bat.
				}
				else if(bat1_y1 < bat1_y1_old)							 // Bat is moving upwards and close to the bottom.
				{
					draw(0, bat1_x1, bat1_x2, bat1_y2, 477);			 // Deletes from the bottom of screen to the bat.
					draw(1, bat1_x1, bat1_x2, bat1_y1, bat1_y1_old);	 // Draws new part of the bat.
				}
			}
			
			adc_value_old1 = adc_value;  // Save bat placement for future comparison.
		}

		// Player 2:
		if (player == 2)
		{
			if (adc_value != adc_value_old2)  // Check for bat movement.
			{
				// Save bat coordinates for future comparison:
				bat2_y1_old = bat2_y1;
				bat2_y2_old = bat2_y2;

				bat2_y1 = SCREEN_HIGHT - (adc_value + 64);  // y1.
				bat2_y2	= SCREEN_HIGHT - (adc_value);		// y2.

				if (bat2_y1 > bat2_y1_old && bat2_y1_old > 101 )		 // Bat is moving downwards and far enough from top of the screen.
				{
					draw(0, bat2_x1, bat2_x2, bat2_y1_old-60, bat2_y1);	 // Delete the old part of the bat and 60 pixels above.
					draw(1, bat2_x1, bat2_x2, bat2_y2_old, bat2_y2);	 // Draws new part of the bat.
				}
				else if (bat2_y1 > bat2_y1_old)							 // Bat moving downwards, close to top edge.
				{
					draw(0, bat2_x1, bat2_x2, 41, bat2_y1);				 // Deletes bat from top of the screen to the new bat placement.
					draw(1, bat2_x1, bat2_x2, bat2_y2_old, bat2_y2);	 // Draws new part of the bat.
				}

				if(bat2_y1 < bat2_y1_old && bat2_y2_old < 417 )			 // Bat is moving upwards and far from bottom of the screen.
				{
					draw(0, bat2_x1, bat2_x2, bat2_y2, bat2_y2_old+60);	 // Deletes old part of the bat and 60 pixels below.
					draw(1, bat2_x1, bat2_x2, bat2_y1, bat2_y1_old);	 // Draws new part of the bat.
				}
				else if(bat2_y1 < bat2_y1_old)							 // Bat is moving upwards and close to the bottom.
				{
					draw(0, bat2_x1, bat2_x2, bat2_y2, 477);			 //Deletes from the bottom of screen to the bat.
					draw(1, bat2_x1, bat2_x2, bat2_y1, bat2_y1_old);	 //Draws new part of the bat.
				}
			}
			
			adc_value_old2 = adc_value;  // Save bat placement for future comparison.
		}
}

/***************************** End Of Module *******************************/
