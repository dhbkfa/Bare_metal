#ifndef SYSTEM_H
#define SYSTEM_H
#include "../../include/cores/arm_cortex_m4.h"
#include "../../include/device/stm32f4xx.h"
void system_clock_init(void);
bool hse_enable(void);
bool pll_enable(void);
#endif