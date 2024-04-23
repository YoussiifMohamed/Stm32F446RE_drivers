/*
 * Rcc_program.c
 *
 *  Created on: Apr 17, 2024
 *      Author: Youssef Mohamed
 */

#include <stdint.h>
#include "BIT_MATH.h"
#include "Rcc_config.h"
#include "Rcc_private.h"
#include "Rcc_interface.h"


ERROR_t MRCC_ERROR_tSetClkStatus(uint8_t Copy_uint8_tClockType , uint8_t Copy_uint8_tStatus)
{
	ERROR_t Loc_ErrorState=NOK;
	uint16_t Loc_timeout=0;

	if (Copy_uint8_tClockType == HSI)
	{
		switch (Copy_uint8_tStatus)
		{
		case ON:
			SET_BIT(MRCC->RCC_CR ,HSION);
			while ( (GET_BIT(MRCC->RCC_CR,HSIRDY)==0) && (Loc_timeout < MAX_TIME_OUT) )
			{
				Loc_timeout++;
			}
			if (Loc_timeout>=MAX_TIME_OUT)
			{
				Loc_ErrorState=TIME_OUT_EXCEDDED;
			}
			else
			{
				Loc_ErrorState=OK;
			}
			break ;
		case OFF:
			CLR_BIT(MRCC->RCC_CR ,HSION);
			while (GET_BIT(MRCC->RCC_CR,HSIRDY)==1);
			Loc_ErrorState=OK;
			break;
		}
	}

	else if(Copy_uint8_tClockType == HSE)
	{
		switch (Copy_uint8_tStatus)
		{
		case ON:
			SET_BIT(MRCC->RCC_CR ,HSEBYP); // because in NUCLEO board HSE is always from MCO from the debugger unit
			SET_BIT(MRCC->RCC_CR ,HSEON);
			while ( (GET_BIT(MRCC->RCC_CR,HSERDY)==0) && (Loc_timeout < MAX_TIME_OUT) )
			{
				Loc_timeout++;
			}
			if (Loc_timeout>=MAX_TIME_OUT)
			{
				Loc_ErrorState=TIME_OUT_EXCEDDED;
			}
			else
			{
				Loc_ErrorState=OK;
			}
			break ;
		case OFF:
			CLR_BIT(MRCC->RCC_CR ,HSEON);
			while (GET_BIT(MRCC->RCC_CR,HSERDY)==1);
			Loc_ErrorState=OK;
			break;
		}
	}

	else if(Copy_uint8_tClockType == PLL)
	{
		switch (Copy_uint8_tStatus)
		{
		case ON:
			SET_BIT(MRCC->RCC_CR ,PLLON);
			while ( (GET_BIT(MRCC->RCC_CR,PLLRDY)==0) && (Loc_timeout < MAX_TIME_OUT) )
			{
				Loc_timeout++;
			}
			if (Loc_timeout>=MAX_TIME_OUT)
			{
				Loc_ErrorState=TIME_OUT_EXCEDDED;
			}
			else
			{
				Loc_ErrorState=OK;
			}
			break ;
		case OFF:
			CLR_BIT(MRCC->RCC_CR ,PLLON);
			while (GET_BIT(MRCC->RCC_CR,PLLRDY)==1);
			Loc_ErrorState=OK;
			break;
		}
	}
	else
	{
		Loc_ErrorState= WRONG_CHOICE; /* Wrong TYPE*/
	}
	return Loc_ErrorState;
}

ERROR_t MRCC_ERROR_tSetSysClk(uint8_t Copy_uint8_tClockType )
{
	ERROR_t Loc_ErrorState=NOK;
	uint8_t Loc_ClkCheck;
	switch (Copy_uint8_tClockType)
	{
	case HSI:
		MRCC->RCC_CFGR&=0xFFFFFFFC;
		Loc_ClkCheck= ((MRCC->RCC_CFGR)>>SWS) & 0x00000003; // to check if the clock system is as configured

		if (Loc_ClkCheck==0)
		{
			Loc_ErrorState=OK;
		}

		break;

	case HSE:
		MRCC->RCC_CFGR= (MRCC->RCC_CFGR & 0xFFFFFFFC) |1;
		Loc_ClkCheck= ((MRCC->RCC_CFGR)>>SWS) & 0x00000003; // to check if the clock system is as configured

		if (Loc_ClkCheck==1)
		{
			Loc_ErrorState=OK;
		}

		break;

	case PLL:
		MRCC->RCC_CFGR= (MRCC->RCC_CFGR & 0xFFFFFFFC) |2; // PLLP
		Loc_ClkCheck= ((MRCC->RCC_CFGR)>>SWS) & 0x00000003; // to check if the clock system is as configured

		if (Loc_ClkCheck==2)
		{
			Loc_ErrorState=OK;
		}

		break;

	default: Loc_ErrorState= WRONG_CHOICE; 	/*Wrong type */
	break;
	}
	return Loc_ErrorState;
}

void MRCC_voidPLLConfig(uint8_t Copy_uint8_tPllSrc ,const  PLL_MUL_t Copy_PLL_MUL_tMultipliersValues)
{
	switch (Copy_uint8_tPllSrc)
	{
	case HSI: CLR_BIT(MRCC->RCC_PLLCFGR,PLLSRC); break;
	case HSE: SET_BIT(MRCC->RCC_PLLCFGR,PLLSRC); break;
	default: /*Wrong SRC */  break;
	}

	switch (Copy_PLL_MUL_tMultipliersValues.pllp)
	{
	case 2:
		CLR_BIT(MRCC->RCC_PLLCFGR,PLLP0);
		CLR_BIT(MRCC->RCC_PLLCFGR,PLLP1);
		break;
	case 4:
		SET_BIT(MRCC->RCC_PLLCFGR,PLLP0);
		CLR_BIT(MRCC->RCC_PLLCFGR,PLLP1);
		break;
	case 6:
		CLR_BIT(MRCC->RCC_PLLCFGR,PLLP0);
		SET_BIT(MRCC->RCC_PLLCFGR,PLLP1);
		break;
	case 8:
		SET_BIT(MRCC->RCC_PLLCFGR,PLLP0);
		SET_BIT(MRCC->RCC_PLLCFGR,PLLP1);
		break;
	}

	if ((Copy_PLL_MUL_tMultipliersValues.plln >49 && Copy_PLL_MUL_tMultipliersValues.plln<433))
	{
		MRCC->RCC_PLLCFGR= (MRCC->RCC_PLLCFGR & 0xFFFF803F) | (Copy_PLL_MUL_tMultipliersValues.plln <<PLLN);
	}

	if ((Copy_PLL_MUL_tMultipliersValues.pllm >1 && Copy_PLL_MUL_tMultipliersValues.pllm<64))
	{
		MRCC->RCC_PLLCFGR= (MRCC->RCC_PLLCFGR & 0xFFFFFFC0) | (Copy_PLL_MUL_tMultipliersValues.pllm);
	}
}

void MRCC_voidAHBPreScaler(uint8_t Copy_uint8Prescaler)
{
	MRCC->RCC_CFGR = (MRCC->RCC_CFGR & 0xFFFFFF0F) | Copy_uint8Prescaler;
}

void MRCC_voidAPB1PreScaler(uint8_t Copy_uint8Prescaler)
{
	MRCC->RCC_CFGR = (MRCC->RCC_CFGR & 0xFFFFE3FF) | Copy_uint8Prescaler;
}

void MRCC_voidAPB2PreScaler(uint8_t Copy_uint8Prescaler)
{
	MRCC->RCC_CFGR = (MRCC->RCC_CFGR & 0xFFFF1FFF) | Copy_uint8Prescaler;
}

void MRCC_voidAHB1EnableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	SET_BIT(MRCC->RCC_AHB1ENR,Copy_uint8PeriphralNumber);
}

void MRCC_voidAHB1DisableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	CLR_BIT(MRCC->RCC_AHB1ENR,Copy_uint8PeriphralNumber);
}

void MRCC_voidAPB1EnableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	SET_BIT(MRCC->RCC_APB1ENR,Copy_uint8PeriphralNumber);
}

void MRCC_voidAPB1DisableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	CLR_BIT(MRCC->RCC_APB1ENR,Copy_uint8PeriphralNumber);
}

void MRCC_voidAPB2EnableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	SET_BIT(MRCC->RCC_APB2ENR,Copy_uint8PeriphralNumber);
}

void MRCC_voidAPB2DisableCLK (uint8_t Copy_uint8PeriphralNumber)
{
	CLR_BIT(MRCC->RCC_APB2ENR,Copy_uint8PeriphralNumber);
}
