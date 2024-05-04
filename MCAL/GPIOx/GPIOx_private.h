/*
 * GPIOx_private.h
 *
 *  Created on: May 1, 2024
 *      Author: joesk
 */

#ifndef GPIOX_PRIVATE_H_
#define GPIOX_PRIVATE_H_

#define GPIOA_BASE_ADDRESS 0x40020000U
#define GPIOB_BASE_ADDRESS 0x40020400U
#define GPIOC_BASE_ADDRESS 0x40020800U
#define GPIOD_BASE_ADDRESS 0x40020C00U
#define GPIOE_BASE_ADDRESS 0x40021000U
#define GPIOF_BASE_ADDRESS 0x40021400U
#define GPIOG_BASE_ADDRESS 0x40021800U
#define GPIOH_BASE_ADDRESS 0x40021C00U

typedef struct
{
	 volatile uint32_t GPIO_MODER;
	 volatile uint32_t GPIO_OTYPER;
	 volatile uint32_t GPIO_OSPEEDR;
	 volatile uint32_t GPIO_PUPDR;
	 volatile uint32_t GPIO_IDR;
	 volatile uint32_t GPIO_ODR;
	 volatile uint32_t GPIO_BSRR;
	 volatile uint32_t GPIO_LCKR;
	 volatile uint32_t GPIO_AFRL;
	 volatile uint32_t GPIO_AFRH;

} GPIO_REGs;

#define MGPIOA	((GPIO_REGs *)GPIOA_BASE_ADDRESS)
#define MGPIOB	((GPIO_REGs *)GPIOB_BASE_ADDRESS)
#define MGPIOC	((GPIO_REGs *)GPIOC_BASE_ADDRESS)
#define MGPIOD	((GPIO_REGs *)GPIOD_BASE_ADDRESS)
#define MGPIOE	((GPIO_REGs *)GPIOE_BASE_ADDRESS)
#define MGPIOF	((GPIO_REGs *)GPIOF_BASE_ADDRESS)
#define MGPIOG	((GPIO_REGs *)GPIOG_BASE_ADDRESS)
#define MGPIOH	((GPIO_REGs *)GPIOH_BASE_ADDRESS)

#define GPIO_PERIPHRALS_NUMBERS   	8



#endif /* GPIOX_PRIVATE_H_ */
