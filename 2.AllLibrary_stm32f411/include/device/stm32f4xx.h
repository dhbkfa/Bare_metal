#ifndef STM32F4xx_H
#define STM32F4xx_H
#include "../include_common.h"

// Define all peripheral
/* PERIPHARAL BASE*/
#define PERIPH_BASE         (0x40000000UL)


// OFFSET ADDRESS
#define AHB1_OFFSET         (0x00020000UL) 
#define APB2_OFFSET         (0x00010000UL)
#define APB1_OFFSET         (0x00000000UL)
#define RCC_OFFSET          (0x00003800UL) 
#define GPIOB_OFFSET        (0x00000400UL)
#define FLASH_OFFSET        (0x00023C00UL)
#define USART1_OFFSET       (0x00001000UL)
#define USART6_OFFSET       (0x00001400UL)
#define USART2_OFFSET       (0x00004400UL)
/* BASE ADDRESS */
#define AHB1_BASE           (PERIPH_BASE + AHB1_OFFSET) // 0x4002 0000
#define APB2_BASE           (PERIPH_BASE + APB2_OFFSET)  // 0x4001 0000
#define APB1_BASE           (PERIPH_BASE + APB1_OFFSET)  // 0x4000 0000

#define RCC_BASE            (AHB1_BASE + RCC_OFFSET) // 0x4002 3800
#define GPIO_BASE           (AHB1_BASE)
#define FLASH_BASE          (PERIPH_BASE + FLASH_OFFSET) //0x4002 3C00

/*REGISTER*/
#define GPIOB               (GPIO_BASE + GPIOB_OFFSET)


/* USART */
#define USART1_ADDRESS              (APB2_BASE + USART1_OFFSET) // 0x4001 1000
#define USART2_ADDRESS              (APB1_BASE + USART2_OFFSET) // 0x4000 4400
#define USART6_ADDRESS              (APB2_BASE + USART6_OFFSET) // 0x4001 1400 




#endif