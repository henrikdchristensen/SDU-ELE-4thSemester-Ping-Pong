/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: main.c
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
#include "collision.h"
#include "ball.h"
#include "bat.h"
#include "adc.h"
#include "reset.h"
#include "midline.h"


/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

extern INT8U var;
INT8U speed = 10;

/*****************************   Functions   *******************************/

int main(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initiates all drivers and schedules the different tasks.
 ***************************************************************************/
{
	INT16U timeout1, timeout2, data0, data1;

	// Initialization of all drivers:
	spi_init();

	timer_init();
	SysTickInit();
	adc_init();
	swkeys_init();
	midline_init();

	// Spawn borders and ball:
	draw(1,0,640,0,3);
	draw(1,0,640,478,480);
	spawnball(2);

    while(1)
    {
		// Runs reset function:
    	reset();
    	if (timer_read()) // Increments timeout variables when a timer event happens.
   		{
    			timeout1++;
    			timeout2++;
   		}
		
		// Runs moveball- and collision tasks:
    	if (timeout1 >= 3)
    	{
			moveball();
			collision();
			midline_update();
			timeout1 = 0;
    	}
		
		// Runs the bat task:
    	if (timeout2 >= 20)
   		{
   			if (adc_read(&data0, &data1))
    		{
   				bat(data1, 2);
   				bat(data0, 1);
   				timeout2 = 0;
   			}
		}
    }
}

/****************************** End Of Module *******************************/
