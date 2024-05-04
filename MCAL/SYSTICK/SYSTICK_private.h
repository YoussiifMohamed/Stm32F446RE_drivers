/*
 * SYSTICK_private.h
 *
 *  Created on: May 4, 2024
 *      Author: joesk
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS	0xE000E010U

/*Bits of STK_CTRL register*/
#define ENABLE  	0u
#define TICKINT  	1u
#define CLKSOURCE  	2u
#define COUNTFLAG  	16u


typedef struct
{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;
} SYSTICK_REGS;

#define MSYSTICK ((SYSTICK_REGS*)SYSTICK_BASE_ADDRESS)

#endif /* SYSTICK_PRIVATE_H_ */
