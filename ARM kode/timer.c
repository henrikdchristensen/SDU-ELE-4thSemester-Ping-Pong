/***************************************************************************
 * University of Southern Denmark
 * Semester Project (PRO)
 *
 * MODULENAME.: timer.c
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
#include "timer.h"

/*****************************  Definitions  *******************************/

#define   FCPU                16000000  // 16MHz CPU speed.
#define   TIMEOUT         	  1         // 1 ms.
#define SYSTICK_RELOAD_VALUE  (((FCPU)/1000) * TIMEOUT)

// Missing definitions in tm4c123gh6pm.h file:
#define NVIC_INT_CTRL_PEND_SYST   0x04000000  // Pend a systick int.
#define NVIC_INT_CTRL_UNPEND_SYST 0x02000000  // Unpend a systick int.

#define SYSTICK_PRIORITY    0x7E

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

INT8U timerflag = 0;
INT8U old_timer = 0;

/*****************************   Functions   *******************************/

void SysTickInit(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : -
 ***************************************************************************/
{
  // Disable systick timer:
  NVIC_ST_CTRL_R &= ~(NVIC_ST_CTRL_ENABLE);

  // Set current systick counter to reload value:
  NVIC_ST_CURRENT_R = SYSTICK_RELOAD_VALUE;

  // Set Reload value, Systick reload register:
  NVIC_ST_RELOAD_R = SYSTICK_RELOAD_VALUE;

  // NVIC systick setup, vector number 15.
  // Clear pending systick interrupt request:
  NVIC_INT_CTRL_R |= NVIC_INT_CTRL_UNPEND_SYST;

  // Set systick priority to 0x10, first clear then set:
  NVIC_SYS_PRI3_R &= ~(NVIC_SYS_PRI3_TICK_M);
  NVIC_SYS_PRI3_R |= (NVIC_SYS_PRI3_TICK_M & (SYSTICK_PRIORITY<<NVIC_SYS_PRI3_TICK_S));

  // Select systick clock source, Use core clock:
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;

  // Enable systick interrupt:
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;

  // Enable and start timer:
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
}

void SysTick_Handler(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Interrupt routine.
 ***************************************************************************/
{
	timerflag++;
}

void enable_global_int()
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Enable interrupts.
 ***************************************************************************/
{
  __asm("cpsie i");
}

void disable_global_int()
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : Disable interrupts.
 ***************************************************************************/
{
  __asm("cpsid i");
}

void timer_init(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : -
 ***************************************************************************/
{
	disable_global_int();
	SysTickInit();
	enable_global_int();
}

INT8U timer_read(void)
/***************************************************************************
 * Input    : -
 * Output   : -
 * Function : -
 ***************************************************************************/
{
	INT8U result;
	result = timerflag;
	timerflag = 0;

	return (result);
}

/***************************** End Of Module *******************************/