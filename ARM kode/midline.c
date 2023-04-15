/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: midline.c
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
#include "draw.h"
#include "ball.h"

/*****************************  Definitions  *******************************/

// Number of blocks present on the screen:
#define	NUMBEROFBLOCKS	12

// Dimensions for the playing area:
#define MAXHIGHT		443
#define MAXWIDTH		640

// Width of the border  (net):
#define BORDERWIDTH		10

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

// Getting old ball coordinates and direction:
extern INT16U x1,x2,x1_old,x2_old,y1,y2,y1_old,y2_old;
extern INT8U direction;

// Calculating coordinates for border placement:
INT16U B1 = ((MAXWIDTH/2)-(BORDERWIDTH/2));  // 320-5 = 315
INT16U B2 = ((MAXWIDTH/2)+(BORDERWIDTH/2));  // 320+5 = 325

// Initialize the Array which are going to save the border:
static INT16U Marr[NUMBEROFBLOCKS][4];

// Initialize coordinates for the border:
static INT16U MLx1;
static INT16U MLx2;
static INT16U MLy1;
static INT16U MLy2;

/*****************************   Functions   *******************************/

void midline_init(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initialize the blocks for the border and save them.
 ***************************************************************************/
{	// Initialize the border (net):
	INT8U hight = (INT8U)(((INT16U)MAXHIGHT / (INT16U)NUMBEROFBLOCKS)/(INT16U)2);
	
	INT8U var = 0;
	INT8U tegn = 0;
	
	// Draw and save each block of the border:
	for (var = 0; var <= (NUMBEROFBLOCKS*2); var++)
	{	
		tegn ^= 1;	// Only draw and save the blocks:
		draw(tegn,B1,B2,(var*hight+37),(var*hight+hight+37));

		if (tegn == 1)
		{	// Save all of the drawn border:
			Marr[var/2][1] = B1;
			Marr[var/2][2] = B2;
			Marr[var/2][3] = var*hight+37;
			Marr[var/2][4] = var*hight+hight+37;
		}
	}
}

// Only updates the midline:
void midline_update(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Check if the ball has entered any of the blocks and recreate it.
 ***************************************************************************/
{	
	if (x2_old > B1 && x1_old < B2)
	{	// If ball are inside of the border:
		INT8U var2 = 0;
		
		for (var2 = 0; var2 < NUMBEROFBLOCKS; var2++)
		{	// Checks which block the ball entered:
			MLy1 = 	Marr[var2][3];
			MLy2 =	Marr[var2][4];

			if (y2_old >= MLy1 && y1_old <= MLy2)
			{	// Draw the block again af the ball leave it:
				draw(1,B1,B2,(Marr[var2][3]),(Marr[var2][4]));
			}
		}
	}
}	

/****************************** End Of Module *******************************/