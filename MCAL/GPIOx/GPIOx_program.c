/*
 * GPIOx_program.c
 *
 *  Created on: May 1, 2024
 *      Author: joesk
 */
#include <stdint.h>
#include "BIT_MATH.h"
#include "ERROR_TYPE.h"
#include "GPIOx_private.h"
#include "GPIOx_interface.h"

GPIO_REGs * GPIO_selector[GPIO_PERIPHRALS_NUMBERS]={MGPIOA,MGPIOB,MGPIOC,MGPIOD,MGPIOE,MGPIOF,MGPIOG,MGPIOH};

ERROR_t MGPIO_ERROR_tPinInit (const PIN_CONFIG_t * PTR_PIN_CONFIG_tPinConfigData)
{
	ERROR_t Loc_errorState=OK;

	if (PTR_PIN_CONFIG_tPinConfigData != NULL)
	{
		if (PTR_PIN_CONFIG_tPinConfigData->PinNum <=PIN_15)
		{
			/*Making the Mode configuration*/
			GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_MODER &=~(3<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));
			GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_MODER |=((PTR_PIN_CONFIG_tPinConfigData->PinMode)<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));

			/*Making the pull type configuration*/
			GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_PUPDR &=~(3<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));
			GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_PUPDR |=((PTR_PIN_CONFIG_tPinConfigData->PinMode)<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));

			/*selecting speed and o/p type */
			if ((PTR_PIN_CONFIG_tPinConfigData->PinMode==AF) ||(PTR_PIN_CONFIG_tPinConfigData->PinMode==OUTPUT))
			{

				/*Making speed configuration */
				GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_OSPEEDR &=~(3<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));
				GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_OSPEEDR |= ((PTR_PIN_CONFIG_tPinConfigData->Speed)<<(2*PTR_PIN_CONFIG_tPinConfigData->PinNum));

				/*Making o/p type*/
				GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_OTYPER &=~(1<<(PTR_PIN_CONFIG_tPinConfigData->PinNum));
				GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_OTYPER |= ((PTR_PIN_CONFIG_tPinConfigData->TypeOfOP)<<(PTR_PIN_CONFIG_tPinConfigData->PinNum));


				/*Making the AF settings for AF pin*/
				if (PTR_PIN_CONFIG_tPinConfigData->PinMode==AF)
				{
					if (PTR_PIN_CONFIG_tPinConfigData->PinNum <= PIN_7)
					{
						GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_AFRL &= ~(15<<(4*PTR_PIN_CONFIG_tPinConfigData->PinNum));
						GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_AFRL |= (PTR_PIN_CONFIG_tPinConfigData->TypeOfAF<<(4*PTR_PIN_CONFIG_tPinConfigData->PinNum));
					}
					else
					{
						GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_AFRH &= ~(15<<(4*PTR_PIN_CONFIG_tPinConfigData->PinNum));
						GPIO_selector[(*PTR_PIN_CONFIG_tPinConfigData).PortName]->GPIO_AFRH |= (PTR_PIN_CONFIG_tPinConfigData->TypeOfAF<<(4*PTR_PIN_CONFIG_tPinConfigData->PinNum));
					}
				}
			}
		}
		else
		{
			Loc_errorState=WRONG_CHOICE;
		}
	}
	else
	{
		Loc_errorState=NULL_PTR_ERROR;
	}

	return Loc_errorState;
}

ERROR_t MGPIO_ERROR_tSetPinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber, PIN_VALUE_t Copy_pin_value_tPinValue)
{
	ERROR_t Loc_ErrorState=CHECK;

	if (Copy_pin_number_tPinNumber <16)
	{
		if (Copy_pin_value_tPinValue == PIN_HIGH)
		{
			switch (Copy_port_name_tPortName)
			{
			case PORT_A: SET_BIT(MGPIOA->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_B: SET_BIT(MGPIOB->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_C: SET_BIT(MGPIOC->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_D: SET_BIT(MGPIOD->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_E: SET_BIT(MGPIOE->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_F: SET_BIT(MGPIOF->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_G: SET_BIT(MGPIOG->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_H: SET_BIT(MGPIOH->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			}
		}
		else if (Copy_pin_value_tPinValue == PIN_LOW)
		{
			switch (Copy_port_name_tPortName)
			{
			case PORT_A: CLR_BIT(MGPIOA->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_B: CLR_BIT(MGPIOB->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_C: CLR_BIT(MGPIOC->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_D: CLR_BIT(MGPIOD->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_E: CLR_BIT(MGPIOE->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_F: CLR_BIT(MGPIOF->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_G: CLR_BIT(MGPIOG->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			case PORT_H: CLR_BIT(MGPIOH->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
			}
		}
		else
		{
			Loc_ErrorState=WRONG_CHOICE;
		}
	}
	else
	{
		Loc_ErrorState=WRONG_CHOICE;
	}
	return Loc_ErrorState;
}

ERROR_t MGPIO_ERROR_tGetPinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber, PIN_VALUE_t * PTR_pin_value_tPinValue)
{
	ERROR_t Loc_ErrorState=CHECK;

	if (Copy_pin_number_tPinNumber <16)
	{
		switch (Copy_port_name_tPortName)
		{
		case PORT_A: *PTR_pin_value_tPinValue=GET_BIT(MGPIOA->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_B: *PTR_pin_value_tPinValue=GET_BIT(MGPIOB->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_C: *PTR_pin_value_tPinValue=GET_BIT(MGPIOC->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_D: *PTR_pin_value_tPinValue=GET_BIT(MGPIOD->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_E: *PTR_pin_value_tPinValue=GET_BIT(MGPIOE->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_F: *PTR_pin_value_tPinValue=GET_BIT(MGPIOF->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_G: *PTR_pin_value_tPinValue=GET_BIT(MGPIOG->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_H: *PTR_pin_value_tPinValue=GET_BIT(MGPIOH->GPIO_IDR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		}
	}
	else
	{
		Loc_ErrorState=WRONG_CHOICE;
	}
	return Loc_ErrorState;
}

ERROR_t MGPIO_ERROR_tTogglePinValue (PORT_NAME_t Copy_port_name_tPortName , PIN_NUMBER_t Copy_pin_number_tPinNumber)
{
	ERROR_t Loc_ErrorState=CHECK;

	if (Copy_pin_number_tPinNumber <16)
	{
		switch (Copy_port_name_tPortName)
		{
		case PORT_A: TOG_BIT(MGPIOA->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_B: TOG_BIT(MGPIOB->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_C: TOG_BIT(MGPIOC->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_D: TOG_BIT(MGPIOD->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_E: TOG_BIT(MGPIOE->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_F: TOG_BIT(MGPIOF->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_G: TOG_BIT(MGPIOG->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		case PORT_H: TOG_BIT(MGPIOH->GPIO_ODR,Copy_pin_number_tPinNumber); Loc_ErrorState=OK; break;
		}
	}
	else
	{
		Loc_ErrorState=WRONG_CHOICE;
	}
	return Loc_ErrorState;

}
