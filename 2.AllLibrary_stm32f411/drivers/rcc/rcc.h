#ifndef RCC_H
#define RCC_H

#include "../../include/cores/arm_cortex_m4.h"

#define RCC         ((struct rcc*)(RCC_BASE))

// Khai báo toàn bộ configure clock có trong stm32f411
struct rcc
{
    union // Clock control register
    {
        volatile uint32_t CR;
        struct
        {
            volatile uint32_t HSION    : 1;  // HSI clock enable
            volatile uint32_t HSIRDY   : 1;  // HSI clock ready
            volatile uint32_t          : 1;
            volatile uint32_t HSITRIM  : 5;  // HSI trimming
            volatile uint32_t HSICAL   : 8;  // HSI calibration
            volatile uint32_t HSEON    : 1;  // HSE clock enable
            volatile uint32_t HSERDY   : 1;  // HSE clock ready
            volatile uint32_t HSEBYP   : 1;  // HSE bypass
            volatile uint32_t CSSON    : 1;  // Clock security system enable
            volatile uint32_t          : 4;
            volatile uint32_t PLLON    : 1;  // Main PLL enable
            volatile uint32_t PLLRDY   : 1;  // Main PLL ready
            volatile uint32_t PLLI2SON : 1;  // PLLI2S enable
            volatile uint32_t PLLI2SRDY: 1;  // PLLI2S ready
            volatile uint32_t          : 4;
        } CR_b;
    };

    union // PLL configuration register
    {
        volatile uint32_t PLLCFGR;
        struct
        {
            volatile uint32_t PLLM    : 6;  // PLL division factor
            volatile uint32_t PLLN    : 9;  // PLL multiplication factor
            volatile uint32_t PLLP    : 2;  // PLL main clock division
            volatile uint32_t         : 4;
            volatile uint32_t PLLSRC  : 1;  // PLL entry clock source
            volatile uint32_t         : 1;
            volatile uint32_t PLLQ    : 4;  // PLL USB/SDIO/RNG division
            volatile uint32_t         : 4;
        } PLLCFGR_b;
    };

    union // Clock configuration register
    {
        volatile uint32_t CFGR;
        struct
        {
            volatile uint32_t SW     : 2;  // System clock switch
            volatile uint32_t SWS    : 2;  // System clock switch status
            volatile uint32_t HPRE   : 4;  // AHB prescaler
            volatile uint32_t PPRE1  : 3;  // APB1 prescaler
            volatile uint32_t PPRE2  : 3;  // APB2 prescaler
            volatile uint32_t RTCPRE : 5;  // RTC clock prescaler
            volatile uint32_t MCO1   : 2;  // Microcontroller clock output 1
            volatile uint32_t I2SSRC : 1;  // I2S clock selection
            volatile uint32_t MCO1PRE: 3;  // MCO1 prescaler
            volatile uint32_t MCO2PRE: 3;  // MCO2 prescaler
            volatile uint32_t MCO2   : 2;  // Microcontroller clock output 2
        } CFGR_b;
    };

    union // Clock interrupt register
    {
        volatile uint32_t CIR;
        struct
        {
            volatile uint32_t LSIRDYF   : 1;  // LSI ready interrupt flag
            volatile uint32_t LSERDYF   : 1;  // LSE ready interrupt flag
            volatile uint32_t HSIRDYF   : 1;  // HSI ready interrupt flag
            volatile uint32_t HSERDYF   : 1;  // HSE ready interrupt flag
            volatile uint32_t PLLRDYF   : 1;  // PLL ready interrupt flag
            volatile uint32_t PLLI2SRDYF: 1;  // PLLI2S ready interrupt flag
            volatile uint32_t CSSF      : 1;  // Clock security interrupt flag
            volatile uint32_t           : 1;
            volatile uint32_t LSIRDYIE  : 1;  // LSI ready interrupt enable
            volatile uint32_t LSERDYIE  : 1;  // LSE ready interrupt enable
            volatile uint32_t HSIRDYIE  : 1;  // HSI ready interrupt enable
            volatile uint32_t HSERDYIE  : 1;  // HSE ready interrupt enable
            volatile uint32_t PLLRDYIE  : 1;  // PLL ready interrupt enable
            volatile uint32_t PLLI2SRDYIE: 1; // PLLI2S ready interrupt enable
            volatile uint32_t           : 1;
            volatile uint32_t           : 1;
            volatile uint32_t LSIRDYC   : 1;  // Clear LSI ready flag
            volatile uint32_t LSERDYC   : 1;  // Clear LSE ready flag
            volatile uint32_t HSIRDYC   : 1;  // Clear HSI ready flag
            volatile uint32_t HSERDYC   : 1;  // Clear HSE ready flag
            volatile uint32_t PLLRDYC   : 1;  // Clear PLL ready flag
            volatile uint32_t PLLI2SRDYC : 1; // Clear PLLI2S ready flag
            volatile uint32_t CSSC      : 1;  // Clear CSS interrupt flag
            volatile uint32_t           : 9;
        } CIR_b;
    };

    union // AHB1 peripheral reset register
    {
        volatile uint32_t AHB1RSTR;
        struct
        {
            volatile uint32_t GPIOARST : 1;
            volatile uint32_t GPIOBRST : 1;
            volatile uint32_t GPIOCRST : 1;
            volatile uint32_t GPIODRST : 1;
            volatile uint32_t GPIOERST : 1;
            volatile uint32_t          : 1;
            volatile uint32_t GPIOHRST : 1;
            volatile uint32_t          : 1;
            volatile uint32_t CRC      : 1;
            volatile uint32_t          : 4;
            volatile uint32_t DMA1RST  : 1;
            volatile uint32_t DMA2RST  : 1;
            volatile uint32_t          : 18;
        } AHB1RSTR_b;
    };

    union // AHB2 peripheral reset register
    {
        volatile uint32_t AHB2RSTR;
        struct
        {
            volatile uint32_t OTGFSRST : 1;  // USB OTG FS reset
            volatile uint32_t          : 31;
        } AHB2RSTR_b;
    };

    uint32_t RESERVED0[2];

    union // APB1 peripheral reset register
    {
        volatile uint32_t APB1RSTR;
        struct
        {
            volatile uint32_t TIM2RST   : 1;
            volatile uint32_t TIM3RST   : 1;
            volatile uint32_t TIM4RST   : 1;
            volatile uint32_t TIM5RST   : 1;
            volatile uint32_t           : 7;
            volatile uint32_t WWDGRST   : 1;
            volatile uint32_t           : 2;
            volatile uint32_t SPI2RST   : 1;
            volatile uint32_t SPI3RST   : 1;
            volatile uint32_t           : 1;
            volatile uint32_t USART2RST : 1;
            volatile uint32_t           : 3;
            volatile uint32_t I2C1RST   : 1;
            volatile uint32_t I2C2RST   : 1;
            volatile uint32_t I2C3RST   : 1;
            volatile uint32_t           : 1;
            volatile uint32_t PWRRST    : 1;
            volatile uint32_t           : 3;
        } APB1RSTR_b;
    };

    union // APB2 peripheral reset register
    {
        volatile uint32_t APB2RSTR;
        struct
        {
            volatile uint32_t TIM1RST   : 1;
            volatile uint32_t           : 3;
            volatile uint32_t USART1RST : 1;
            volatile uint32_t USART6RST : 1;
            volatile uint32_t           : 2;
            volatile uint32_t ADCRST    : 1;
            volatile uint32_t           : 2;
            volatile uint32_t SDIORST   : 1;
            volatile uint32_t SPI1RST   : 1;
            volatile uint32_t SPI4RST   : 1;
            volatile uint32_t SYSCFGRST : 1;
            volatile uint32_t           : 1;
            volatile uint32_t TIM9RST   : 1;
            volatile uint32_t TIM10RST  : 1;
            volatile uint32_t TIM11RST  : 1;
            volatile uint32_t           : 13;
        } APB2RSTR_b;
    };

    uint32_t RESERVED1[2];

    union // AHB1 peripheral clock enable register
    {
        volatile uint32_t AHB1ENR;
        struct
        {
            volatile uint32_t GPIOAEN : 1;
            volatile uint32_t GPIOBEN : 1;
            volatile uint32_t GPIOCEN : 1;
            volatile uint32_t GPIODEN : 1;
            volatile uint32_t GPIOEEN : 1;
            volatile uint32_t         : 1;
            volatile uint32_t GPIOHEN : 1;
            volatile uint32_t         : 1;
            volatile uint32_t CRCEN   : 1;
            volatile uint32_t         : 4;
            volatile uint32_t DMA1EN  : 1;
            volatile uint32_t DMA2EN  : 1;
            volatile uint32_t         : 18;
        } AHB1ENR_b;
    };

    union // AHB2 peripheral clock enable register
    {
        volatile uint32_t AHB2ENR;
        struct
        {
            volatile uint32_t OTGFSEN : 1;  // USB OTG FS clock enable
            volatile uint32_t         : 31;
        } AHB2ENR_b;
    };

    uint32_t RESERVED2[2];

    union // APB1 peripheral clock enable register
    {
        volatile uint32_t APB1ENR;
        struct
        {
            volatile uint32_t TIM2EN   : 1;
            volatile uint32_t TIM3EN   : 1;
            volatile uint32_t TIM4EN   : 1;
            volatile uint32_t TIM5EN   : 1;
            volatile uint32_t           : 7;
            volatile uint32_t WWDGEN   : 1;
            volatile uint32_t           : 2;
            volatile uint32_t SPI2EN   : 1;
            volatile uint32_t SPI3EN   : 1;
            volatile uint32_t           : 1;
            volatile uint32_t USART2EN : 1;
            volatile uint32_t           : 3;
            volatile uint32_t I2C1EN   : 1;
            volatile uint32_t I2C2EN   : 1;
            volatile uint32_t I2C3EN   : 1;
            volatile uint32_t           : 1;
            volatile uint32_t PWREN    : 1;
            volatile uint32_t           : 3;
        } APB1ENR_b;
    };

    union // APB2 peripheral clock enable register
    {
        volatile uint32_t APB2ENR;
        struct
        {
            volatile uint32_t TIM1EN   : 1;
            volatile uint32_t           : 3;
            volatile uint32_t USART1EN : 1;
            volatile uint32_t USART6EN : 1;
            volatile uint32_t           : 2;
            volatile uint32_t ADC1EN   : 1;
            volatile uint32_t           : 2;
            volatile uint32_t SDIOEN   : 1;
            volatile uint32_t SPI1EN   : 1;
            volatile uint32_t SPI4EN   : 1;
            volatile uint32_t SYSCFGEN : 1;
            volatile uint32_t           : 1;
            volatile uint32_t TIM9EN   : 1;
            volatile uint32_t TIM10EN  : 1;
            volatile uint32_t TIM11EN  : 1;
            volatile uint32_t           : 13;
        } APB2ENR_b;
    };

    uint32_t RESERVED3[2];

    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;

    uint32_t RESERVED4[2];

    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;

    uint32_t RESERVED5[2];

    union // Backup domain control register
    {
        volatile uint32_t BDCR;
        struct
        {
            volatile uint32_t LSEON    : 1;
            volatile uint32_t LSERDY   : 1;
            volatile uint32_t LSEBYP   : 1;
            volatile uint32_t          : 5;
            volatile uint32_t RTCSEL   : 2;
            volatile uint32_t          : 5;
            volatile uint32_t RTCEN    : 1;
            volatile uint32_t BDRST    : 1;
            volatile uint32_t          : 16;
        } BDCR_b;
    };

    union // Control/status register
    {
        volatile uint32_t CSR;
        struct
        {
            volatile uint32_t LSION    : 1;
            volatile uint32_t LSIRDY   : 1;
            volatile uint32_t          : 22;
            volatile uint32_t RMVF     : 1;
            volatile uint32_t BORRSTF  : 1;
            volatile uint32_t PADRSTF  : 1;
            volatile uint32_t PORRSTF  : 1;
            volatile uint32_t SFTRSTF  : 1;
            volatile uint32_t IWDGRSTF : 1;
            volatile uint32_t WWDGRSTF : 1;
            volatile uint32_t LPWRRSTF : 1;
        } CSR_b;
    };

    uint32_t RESERVED6[2];

    union // Spread spectrum clock generation register
    {
        volatile uint32_t SSCGR;
        struct
        {
            volatile uint32_t MODPER   : 13;
            volatile uint32_t INCSTEP  : 15;
            volatile uint32_t RESERVED : 2;
            volatile uint32_t SPREADSEL: 1;
            volatile uint32_t SSCGEN   : 1;
        } SSCGR_b;
    };

    union // PLLI2S configuration register
    {
        volatile uint32_t PLLI2SCFGR;
        struct
        {
            volatile uint32_t PLLI2SM : 6;
            volatile uint32_t PLLI2SN : 9;
            volatile uint32_t         : 13;
            volatile uint32_t PLLI2SR : 3;
            volatile uint32_t         : 1;
        } PLLI2SCFGR_b;
    };

    volatile uint32_t RESERVED7;

    union // Dedicated clock configuration register
    {
        volatile uint32_t DCKCFGR;
        struct
        {
            volatile uint32_t PLLI2SDIVQ : 5;
            volatile uint32_t            : 27;
        } DCKCFGR_b;
    };
};

#endif