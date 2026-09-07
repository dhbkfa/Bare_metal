#include "systick.h"

volatile uint32_t s_ticks = 0;
void systick_init(uint32_t tick_hz){
	uint32_t ticks = (tick_hz / 1000U);		// 
	SYSTICK -> CSR_b.ENABLE = 0; 			// Disable Systick during setup
	SYSTICK -> RVR = ticks - 1;				// Set reload register
	SYSTICK -> CVR = 0;						// Clear current value register
	SYSTICK -> CSR_b.CLKSOURCE = 1;			//	Use processor clock
	SYSTICK -> CSR_b.TICKINT = 1;			// Enable Systick interrupt
	SYSTICK -> CSR_b.ENABLE = 1;  			// Enable Systick 
}
// Systick interupt handler
void SysTick_Handler(void)
{
    ++s_ticks;
}
// 