
#include "../lib/stm32f4xx.h"
#include "../lib/gpio.h"

extern void _estack(void);                                        
void main(void)
{
    blinkled('C',13,GPIO_MODE_OUTPUT);
    return;
    
}

__attribute__ ((naked,noreturn)) void Reset_Handler(void)
{
    extern long _sbss,_ebss,_sdata,_edata,_sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++)
    {
        *dst = 0;
    }
    for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;)
    {
        *dst++ = *src++;
    }
    main();
    for(;;)(void)0;
    
};
// 16 standard and 91 STM32-specific handles
__attribute__((section(".isr_vector"))) void(*const tab[16 + 91])(void) = {
    _estack,Reset_Handler};

