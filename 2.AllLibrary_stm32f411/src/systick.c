#include "../lib/systick.h"

extern volatile uint32_t s_ticks = 0;
void systick_init(uint32_t ticks){
	SYSTICK -> RVR = ticks - 1;
	SYSTICK -> CVR = 0;
	SYSTICK -> CSR = BIT(0) |  BIT(1) | BIT(2); 
}
void SysTick_Handler(void)
{
    ++s_ticks;
}
