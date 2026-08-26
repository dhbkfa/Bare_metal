#ifndef SYSTICK_H
#define SYSTICK_H
#include "stm32f4xx.h"
// Declare the systicks in the system
struct systick{
	volatile uint32_t CSR,RVR,
		          CVR,CALIB;
};
void systick_init(uint32_t ticks);
void SysTick_Handler(void);

#endif