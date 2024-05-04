/*
 * ERROR_TYPE.h
 *
 *  Created on: May 1, 2024
 *      Author: joesk
 */

#ifndef ERROR_TYPE_H_
#define ERROR_TYPE_H_


#define NULL (void*)0

#define ON 	1U
#define OFF 0U

typedef enum
{
	OK=1,
	NOK,
	NULL_PTR_ERROR,
	CHECK,
	TIME_OUT_EXCEDDED,
	WRONG_CHOICE
} ERROR_t;

#endif /* ERROR_TYPE_H_ */
