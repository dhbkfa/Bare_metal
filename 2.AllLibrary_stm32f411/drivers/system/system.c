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
    // Flash lantency & Caches for 100Mhz
    FLASH->ACR_b.LATENCY = FLASH_LATENCY;
    FLASH->ACR_b.PRFTEN = 1;
    FLASH->ACR_b.ICEN = 1;
    FLASH->ACR_b.DCEN = 1;

    // Enable HSE
    RCC -> CR_b.HSEON = 1; // Set HSE(High speed enable) ON
    if(!hse_enable()) // Wait for HSERDY
    {
        while (1);
        
        //printf("High speed disabled after 1,000,000 loops");
    } 
    // Bus Prescaler(Bo dem truoc) : AHB/1 , APB2 / 2, APB1 / 4
    //RCC->CFGR_b.HPRE = 0;
    /* Bo sung enable cho APB1 va APB2 */


    // Configure PLL
    RCC->CFGR &= ~((0x7U << 10) | (0x7U << 13));

    // Clear and set M,N,P and importanly: Set bit 22 to select HSE as source
    RCC->PLLCFGR_b.PLLM = PLL_M;
    RCC->PLLCFGR_b.PLLN = PLL_N;
    RCC->PLLCFGR_b.PLLP = (PLL_P >> 1) - 1;
    RCC->PLLCFGR_b.PLLSRC = 1; // Use HSE as PLL source

   // RCC->CFGR |= (0x4U << 10);
    // Enable PLL
    RCC->CR_b.PLLON = 1;         // Set PLLON
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