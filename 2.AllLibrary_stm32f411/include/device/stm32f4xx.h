#ifndef STM32F4xx_H
#define STM32F4xx_H
#include "../include_common.h"

// Define all peripheral
/* PERIPHARAL BASE*/
#define PERIPH_BASE         (0x40000000UL)


// OFFSET ADDRESS
#define AHB1_OFFSET         (0x00020000UL) 
#define RCC_OFFSET          (0x00003800UL) 
#define GPIOB_OFFSET        (0x00000400UL)
#define FLASH_OFFSET        (0x00023C00UL)

/* BASE ADDRESS */
#define AHB1_BASE           (PERIPH_BASE + AHB1_OFFSET) // 0x4002 0000
#define RCC_BASE            (AHB1_BASE + RCC_OFFSET) // 0x4002 3800
#define GPIO_BASE           (AHB1_BASE)
#define FLASH_BASE          (PERIPH_BASE + FLASH_OFFSET) //0x4002 3C00
/*REGISTER*/
#define GPIOB               (GPIO_BASE + GPIOB_OFFSET)





#endif