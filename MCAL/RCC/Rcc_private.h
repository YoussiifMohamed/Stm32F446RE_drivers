/*
 * Rcc_private.h
 *
 *  Created on: Apr 17, 2024
 *      Author: Youssef Mohamed
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_BASE_ADDRESS 0x40023800

/*RCC_CR*/
#define PLLRDY	25
#define PLLON	24
#define	CSSON	19
#define	HSEBYP	18
#define	HSERDY	17
#define	HSEON	16
#define	HSIRDY	1
#define	HSION	0
/*RCC_PLLCFGR*/
#define PLLSRC	22
#define	PLLP0 	16
#define	PLLP1 	17
#define	PLLN 	6
#define	PLLM 	0
/*RCC_CFGR*/
#define	PPRE2	13	//3 bits
#define	PPRE1	10  //3 bits
#define	HPRE	4	//4 bits
#define	SWS		2
#define	SW		0
/*RCC_AHB1ENR*/
#define	DMA2EN	22
#define	DMA1EN	21
#define	CRCEN	12
#define	GPIOHEN	7
#define	GPIOGEN	6
#define	GPIOFEN	5
#define	GPIOEEN	4
#define	GPIODEN	3
#define	GPIOCEN	2
#define	GPIOBEN	1
#define	GPIOAEN	0
/*RCC_APB1ENR*/
#define	DACEN	29
#define	PWREN	28
#define	CECEN	27
#define	CAN2EN	26
#define	CAN1EN	25
#define	I2C3EN	23
#define	I2C2EN	22
#define	I2C1EN	21
#define	UART5EN	20
#define	UART4EN	19
#define	UART3EN	18
#define	UART2EN	17
#define	SPI3EN	15
#define	SPI2EN	14
#define	WWDGEN	11
#define	TIM14EN	8
#define	TIM13EN	7
#define	TIM12EN	6
#define	TIM7EN	5
#define	TIM6EN	4
#define	TIM5EN	3
#define	TIM4EN	2
#define	TIM3EN	1
#define	TIM2EN	0
/*RCC_APB2ENR*/
#define	TIM11EN	    18
#define	TIM10EN	    17
#define	TIM9EN	    16
#define	SYSCFGEN	14
#define	SPI4EN	    13
#define	SPI1EN	    12
#define	ADC3EN	    10
#define	ADC2EN	    9
#define	ADC1EN	    8
#define	USART6EN	5
#define	USART1EN	4
#define	TIM8EN	    1
#define	TIM1EN	    0


typedef struct
{
	uint32_t RCC_CR;
	uint32_t RCC_PLLCFGR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_AHB1RSTR;
	uint32_t RCC_AHB2RSTR;
	uint32_t RCC_AHB3RSTR;
	uint32_t RESERVED1;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_APB2RSTR;
	uint32_t RESERVED2;
	uint32_t RESERVED3;
	uint32_t RCC_AHB1ENR;
	uint32_t RCC_AHB2ENR;
	uint32_t RCC_AHB3ENR;
	uint32_t RESERVED4;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_APB2ENR;
	uint32_t RESERVED5;
	uint32_t RESERVED6;
	uint32_t RCC_AHB1LPENR;
	uint32_t RCC_AHB2LPENR;
	uint32_t RCC_AHB3LPENR;
	uint32_t RESERVED7;
	uint32_t RCC_APB1LPENR;
	uint32_t RCC_APB2LPENR;
	uint32_t RESERVED8;
	uint32_t RESERVED9;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	uint32_t RESERVED10;
	uint32_t RESERVED11;
	uint32_t RCC_SSCGR;
	uint32_t RCC_PLLI2SCFGR;
	uint32_t RCC_PLLSAICFGR;
	uint32_t RCC_DCKCFGR;
	uint32_t RCC_CKGATENR;
	uint32_t RCC_DCKCFGR2;

} RCC_REGs;

#define MRCC ((volatile RCC_REGs *)RCC_BASE_ADDRESS)

#endif /* RCC_PRIVATE_H_ */
