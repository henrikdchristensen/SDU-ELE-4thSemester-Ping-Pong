/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: adc.h
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

#ifndef _ADC_H
#define _ADC_H

/***************************** Include files *******************************/

/*****************************  Definitions  *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void adc_init(void);
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Initialize the ADC.
 ***************************************************************************/

INT16U adc_read(INT16U *pdata0, INT16U *pdata1);
/***************************************************************************
 * Input    : Take two integers as inputs.
 * Output   : If any changes output is 1.
 * Function : pdata0 store changes and pdata1 store changes when push.
 ***************************************************************************/

/***************************** End Of Module *******************************/

#endif
