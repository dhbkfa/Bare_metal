#ifndef SYSTICK_H
#define SYSTICK_H
#include "../../include/cores/arm_cortex_m4.h"
extern volatile uint32_t s_ticks;
void systick_init(uint32_t tick_hz);
void SysTick_Handler(void);

#endif