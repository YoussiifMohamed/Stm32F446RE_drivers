/*
 * SYSTICK_config.h
 *
 *  Created on: May 4, 2024
 *      Author: joesk
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

typedef enum
{
	AHB_OVER_8=0,
	AHB
}SYSTICK_PRESCALER;

#define SYSTICK_PRESCALER  AHB

#define SYSTEM_FREQ  8000000U


#endif /* SYSTICK_CONFIG_H_ */
