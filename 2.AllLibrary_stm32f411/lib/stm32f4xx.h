#ifndef STM32F4xx_H
#define STM32F4xx_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
// Quy uoc dat bit
#define BIT(x)   (1UL << (x))
#define PIN(bank,num) (((bank - 'A') << 8) | (num))
#define PINNO(pin)    (pin & 255)   
#define PINBANK(pin)    (pin >> 8)

// Define all peripheral
/* PERIPHARAL BASE*/
#define PERIPH_BASE         (0x40000000UL)
#define Internal_BASE   	(0xE0000000UL)



// OFFSET ADDRESS
#define AHB1_OFFSET         (0x00020000UL) 
#define RCC_OFFSET          (0x00003800UL) 
#define GPIOB_OFFSET        (0x00000400UL)
#define Systick_OFFSET	    (0x0000E010UL)

/* BASE ADDRESS */
#define AHB1_BASE           (PERIPH_BASE + AHB1_OFFSET) // 0x4002 0000
#define RCC_BASE            (AHB1_BASE + RCC_OFFSET) // 0x4002 3800
#define GPIO_BASE           (AHB1_BASE)
/*REGISTER*/
#define GPIOB               (GPIO_BASE + GPIOB_OFFSET)
#define Systick_Timer	    (Internal_BASE + Systick_OFFSET)
/* Define GPIO*/
#define GPIO(bank)  ((struct gpio*)((GPIO_BASE + (0x400*bank)))) // Cho phep lay dia chi cua cac GPIO: A,B,C
#define RCC         ((struct rcc*)(RCC_BASE))
#define SYSTICK     ((struct systick*) Systick_Timer) // Cho phep lay cac thanh ghi cau hinh trong systick
// Khai báo toàn bộ configure clock có trong stm32f411
struct rcc
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;

    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED0[2];

    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];

    volatile uint32_t AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    uint32_t RESERVED2[2];

    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED3[2];

    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t RESERVED4[2];

    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED5[2];

    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED6[2];

    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t RESERVED7;
    volatile uint32_t DCKCFGR;
};


#endif
