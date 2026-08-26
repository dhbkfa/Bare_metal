
#include "../lib/blinkled.h"


extern void _estack(void);                                        
void main(void)
{
    float frequencys = 16000000/1000;
    blinkled('C',13,GPIO_MODE_OUTPUT,frequencys);
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
    _estack,Reset_Handler,0,0,0,0,0,0,0,0,0,0,0,0,0,SysTick_Handler};

