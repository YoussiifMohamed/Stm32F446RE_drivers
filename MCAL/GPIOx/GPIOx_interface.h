/*
 * GPIOx_interface.h
 *
 *  Created on: May 1, 2024
 *      Author: joesk
 */

#ifndef GPIOX_INTERFACE_H_
#define GPIOX_INTERFACE_H_

typedef enum
{
	INPUT=0,
	OUTPUT,
	AF,
	Analog
}PIN_MODE;

typedef enum
{
	PUSH_PULL=0,
	OPEN_DRAIN
}OUTPUT_TYPE;

typedef enum
{
	LOW_SPEED=0,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
}SPEED_TYPE;

typedef enum
{
	FLOATING=0,
	PULL_UP,
	PULL_DOWN
}PULL_TYPE;

typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}ALTFUNC_t;

typedef enum
{
	PORT_A=0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F,
	PORT_G,
	PORT_H
}PORT_NAME_t;

typedef enum
{
	PIN_0=0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15

}PIN_NUMBER_t;

typedef enum
{
	PIN_LOW=0,
	PIN_HIGH

}PIN_VALUE_t;

typedef struct
{
	PORT_NAME_t PortName;
	PIN_NUMBER_t PinNum;
	PIN_MODE PinMode;
	SPEED_TYPE Speed;
	PULL_TYPE PullType;
	OUTPUT_TYPE TypeOfOP;
	ALTFUNC_t TypeOfAF;

}PIN_CONFIG_t;

ERROR_t MGPIO_ERROR_tPinInit (const PIN_CONFIG_t * PTR_PIN_CONFIG_tPinConfigData);

ERROR_t MGPIO_ERROR_tSetPinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber, PIN_VALUE_t Copy_pin_value_tPinValue);

ERROR_t MGPIO_ERROR_tGetPinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber, PIN_VALUE_t * PTR_pin_value_tPinValue);

ERROR_t MGPIO_ERROR_tTogglePinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber);

#endif /* GPIOX_INTERFACE_H_ */
