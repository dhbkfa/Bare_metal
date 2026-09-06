#include "systick.h"

volatile uint32_t s_ticks = 0;
void systick_init(uint32_t tick_hz){
	uint32_t ticks = (tick_hz / 1000U);		// 
	SYSTICK -> RVR = ticks - 1;				// Set reload register
	SYSTICK -> CVR = 0;						// Clear current value register
	SYSTICK -> CSR = BIT(0) |  BIT(1) | BIT(2); 	// Enable Systick , use processor clock
}
// Systick interupt handler
void SysTick_Handler(void)
{
    ++s_ticks;
}
// 