#include "system.h"
bool hse_enable(void)
{
    uint32_t timeout = 1000000;
    while (!(RCC->CR & BIT(17)))
    {
        if (--timeout == 0)
        {
            return false;
        }
        
    }
    return true;
}
bool pll_enable(void)
{
    uint32_t timeout = 1000000;
    while (!(RCC->CR & BIT(25)))
    {
        if (--timeout == 0)
        {
            return false;
        }
        
    }
    return true;
}
/* Thiết lập xung clock từ 16Mhz lên đến 100Mhz*/
void system_clock_init(void){

    // Enable FTU and flash Latency (Keep original guide code here)
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); // Coprocessor Access control register full access
    FLASH->ACR &= ~0xFU;
    FLASH->ACR |= FLASH_LATENCY | BIT(8) | BIT(9); // Flash letency , prefetch

    // Enable HSE
    RCC -> CR |= BIT (16); // Set HSE(High speed enable) ON
    if(!hse_enable()) // Wait for HSERDY
    {
        while (1);
        
        //printf("High speed disabled after 1,000,000 loops");
    } 
    

    // Configure PLL
    RCC->CFGR &= ~((0x7U << 10) | (0x7U << 13));

    // Clear and set M,N,P and importanly: Set bit 22 to select HSE as source
    RCC->PLLCFGR = (PLL_M << 0) | (PLL_N << 6) | (((PLL_P >> 1) - 1) << 16) | BIT(22);
    RCC->CFGR |= (0x4U << 10);
    // Enable PLL
    RCC->CR |= BIT(24);         // Set PLLON
    if(!pll_enable()) // Wait for PLLRDY
    {
        while (1);
        //printf("PLL disabled after 1,000,000 loops");
    } 
  
    // Select PLL as System Clock
    RCC->CFGR &= ~(uint32_t)3;          // Clear SW bits
    RCC->CFGR |= 2;                     // Select PLL (0b10)
    while(((RCC->CFGR) & (3 << 2)) != (2 << 2));  // Wait for SWS to indicate PLL
    
    
} 