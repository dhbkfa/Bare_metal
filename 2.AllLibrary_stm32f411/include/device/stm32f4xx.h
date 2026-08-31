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

/* Define GPIO*/
#define GPIO(bank)  ((struct gpio*)((GPIO_BASE + (0x400*bank)))) // Cho phep lay dia chi cua cac GPIO: A,B,C
#define RCC         ((struct rcc*)(RCC_BASE))

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
/* Định nghĩa các thanh ghi cho gpio */
struct gpio {
    volatile uint32_t
        MODER,
        OTYPER,
        OSPEEDR,
        PUPDR,
        IDR,
        ODR,
        BSRR,
        LCKR,
        AFR[2];
};
// Enum values are per datasheet : 0 , 1 , 2 , 3
enum{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
};
enum{
    APB1_PRE = 4, /* AHB clock*/
    APB2_PRE = 4
};
enum{
    PLL_HSE = 16,
    PLL_M = 8,
    PLL_N = 100,
    PLL_P = 2
};
/* Define clock system */
#define FLASH_LATENCY   3
#define SYS_FREQUENCY   ((PLL_HSE * PLL_N / PLL_M / PLL_P) * 1000000)
#define APB2_FREQUENCY  (SYS_FREQUENCY / (BIT(APB2_PRE - 3)))
#define APB1_FREQUENCY  (SYS_FREQUENCY / (BIT(APB1_PRE - 3)))
/* The register control flash */
struct flash
{
    volatile uint32_t ACR;          // Access control register
    volatile uint32_t KEYR;         // Key register
    volatile uint32_t OPTKEYR;      // Option key register 
    volatile uint32_t SR;           // Status register
    volatile uint32_t CR;           // Control register
    volatile uint32_t OPTCR;        // Option control register


};
#define FLASH ((struct flash*) FLASH_BASE)

#endif