/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: midline.h
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

#ifndef _MIDLINE_H
#define _MIDLINE_H

/***************************** Include files *******************************/

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void midline_init(void); 
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initialize the blocks for the border and save them.
 ***************************************************************************/
  
void midline_update(void);
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Check if the ball has entered any of the blocks and recreate it.
 ***************************************************************************/
 
/***************************** End Of Module *******************************/

#endif
