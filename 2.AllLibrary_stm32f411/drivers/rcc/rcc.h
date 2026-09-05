#ifndef RCC_H
#define RCC_H

#include "../../include/cores/arm_cortex_m4.h"

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

#endif