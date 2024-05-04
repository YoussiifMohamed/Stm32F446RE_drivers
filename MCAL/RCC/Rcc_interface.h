/*
 * Rcc_interface.h
 *
 *  Created on: Apr 17, 2024
 *      Author: Youssef Mohamed
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define HSI	1
#define HSE	2
#define PLL	3

typedef enum
{
	NOT_DIVIDED=0,
	DIVIDED_BY_2=8,
	DIVIDED_BY_4,
	DIVIDED_BY_8,
	DIVIDED_BY_16,
	DIVIDED_BY_64,
	DIVIDED_BY_128,
	DIVIDED_BY_256,
	DIVIDED_BY_512

} AHB_PRESCALER;

typedef enum
{
	NOTDIVIDED=0,
	DIVIDED__BY_2=4,
	DIVIDED__BY_4,
	DIVIDED__BY_8,
	DIVIDED__BY_16

} APB_PRESCALER;


typedef struct
{
	uint8_t pllp;
	uint8_t pllm;
	uint16_t plln;
} PLL_MUL_t;

typedef enum
{
	GPIOA
} AHB1_PERIPHERAL;


ERROR_t MRCC_ERROR_tSetClkStatus(uint8_t Copy_uint8_tClockType , uint8_t Copy_uint8_tStatus);

ERROR_t MRCC_ERROR_tSetSysClk(uint8_t Copy_uint8_tClockType );

void MRCC_voidPLLConfig(uint8_t Copy_uint8_tPllSrc ,const PLL_MUL_t * PTR_PLL_MUL_tMultipliersValues);

void MRCC_voidAHBPreScaler(AHB_PRESCALER Copy_AHB_PRESCALERPrescaler);

void MRCC_voidAPB1PreScaler(APB_PRESCALER Copy_APB_PRESCALERPrescaler);

void MRCC_voidAPB2PreScaler(APB_PRESCALER Copy_APB_PRESCALERPrescaler);

void MRCC_voidAHB1EnableCLK (AHB1_PERIPHERAL Copy_AHB1_PERIPHERALPeriphralNumber);

void MRCC_voidAHB1DisableCLK (AHB1_PERIPHERAL Copy_AHB1_PERIPHERALPeriphralNumber);

void MRCC_voidAPB1EnableCLK (uint8_t Copy_uint8PeriphralNumber);

void MRCC_voidAPB1DisableCLK (uint8_t Copy_uint8PeriphralNumber);

void MRCC_voidAPB2EnableCLK (uint8_t Copy_uint8PeriphralNumber);

void MRCC_voidAPB2DisableCLK (uint8_t Copy_uint8PeriphralNumber);


#endif /* RCC_INTERFACE_H_ */
