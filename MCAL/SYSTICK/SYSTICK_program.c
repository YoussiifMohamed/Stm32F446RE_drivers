/*
 * SYSTICK_program.c
 *
 *  Created on: May 4, 2024
 *      Author: joesk
 */

#include <stdint.h>
#include "BIT_MATH.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"

void MSYSTICK_voidDelayMiliSec(uint16_t Copy_uint16_tReqTime)
{
	float Loc_timerFreq;

	/*Calculating the timer freq*/
	if (SYSTICK_PRESCALER == AHB)
	{
		SET_BIT(MSYSTICK->STK_CTRL,CLKSOURCE);
		Loc_timerFreq=(float)SYSTEM_FREQ;
	}
	else /* (SYSTICK_PRESCALER == AHB_OVER_8)*/
	{
		CLR_BIT(MSYSTICK->STK_CTRL,CLKSOURCE);
		Loc_timerFreq=(float)SYSTEM_FREQ/8.0;
	}

	/*Calculating TickTime*/
	float Loc_tickTime=(1/Loc_timerFreq);

	/*Calculating Number of ticks corresponding to req time*/
	float Loc_numberOfTicks= ((float)Copy_uint16_tReqTime /1000.0)/Loc_tickTime ;

	/*Setting the ticks corresponding to req time in reg*/
	MSYSTICK->STK_LOAD=Loc_numberOfTicks;

	/*enable the timer*/
	SET_BIT(MSYSTICK->STK_CTRL,ENABLE);

	/*wait till the req time finished*/
	while (  (GET_BIT(MSYSTICK->STK_CTRL,COUNTFLAG)) == 0);

	/*Stop the Timer*/
	CLR_BIT(MSYSTICK->STK_CTRL,ENABLE);

	/*initialise the registers*/
	MSYSTICK->STK_VAL=0;  // this clears also the flag
	MSYSTICK->STK_LOAD=0;
}


void MSYSTICK_voidDelayMicroSec(uint32_t Copy_uint32_tReqTime)
{
	float Loc_timerFreq;

	/*Calculating the timer freq*/
	if (SYSTICK_PRESCALER == AHB)
	{
		SET_BIT(MSYSTICK->STK_CTRL,CLKSOURCE);
		Loc_timerFreq=(float)SYSTEM_FREQ;
	}
	else /* (SYSTICK_PRESCALER == AHB_OVER_8)*/
	{
		CLR_BIT(MSYSTICK->STK_CTRL,CLKSOURCE);
		Loc_timerFreq=(float)SYSTEM_FREQ/8.0;
	}

	/*Calculating TickTime*/
	float Loc_tickTime=(1/Loc_timerFreq);

	/*Calculating Number of ticks corresponding to req time*/
	float Loc_numberOfTicks= ( (float)Copy_uint32_tReqTime /1000000.0) /Loc_tickTime ;

	/*Setting the ticks corresponding to req time in reg*/
	MSYSTICK->STK_LOAD=Loc_numberOfTicks;

	/*enable the timer*/
	SET_BIT(MSYSTICK->STK_CTRL,ENABLE);

	/*wait till the req time finished*/
	while (  (GET_BIT(MSYSTICK->STK_CTRL,COUNTFLAG)) == 0);

	/*Stop the Timer*/
	CLR_BIT(MSYSTICK->STK_CTRL,ENABLE);

	/*initialise the registers*/
	MSYSTICK->STK_VAL=0;  // this clears also the flag
	MSYSTICK->STK_LOAD=0;
}
