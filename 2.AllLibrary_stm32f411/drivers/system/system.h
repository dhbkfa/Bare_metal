#ifndef SYSTEM_H
#define SYSTEM_H
#include "../../include/cores/arm_cortex_m4.h"
#include "../../include/device/stm32f4xx.h"
#include "../scb/scb.h"
#include "../rcc/rcc.h"
#include "../flash/flash.h"
void system_clock_init(void);
bool hse_enable(void);
bool pll_enable(void);
enum{
    APB1_PRE = 4, /* AHB clock*/
    APB2_PRE = 4
};
enum{
    PLL_HSE = 16,
    PLL_M = 8,
    PLL_N = 70,
    PLL_P = 2
};
/* Define clock system */
#define FLASH_LATENCY   3
#define SYS_FREQUENCY   ((PLL_HSE * PLL_N / PLL_M / PLL_P) * 1000000)
#define APB2_FREQUENCY  (SYS_FREQUENCY / (BIT(APB2_PRE - 3)))
#define APB1_FREQUENCY  (SYS_FREQUENCY / (BIT(APB1_PRE - 3)))
#endif