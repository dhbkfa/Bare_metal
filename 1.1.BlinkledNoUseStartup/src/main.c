#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#define BIT(x)   (1UL << (x))
#define PIN(bank,num) (((bank - 'A') << 8) | (num))
#define PINNO(pin)    (pin & 255)   
#define PINBANK(pin)    (pin >> 8)
// Define all peripheral
/* PERIPHARAL BASE*/
#define PERIPH_BASE         (0x40000000UL)
// OFFSET ADDRESS
#define AHB1_OFFSET         (0x00020000UL) 
#define RCC_OFFSET          (0x00003800UL) 
#define GPIOB_OFFSET        (0x00000400)

/* BASE ADDRESS */
#define AHB1_BASE           (PERIPH_BASE + AHB1_OFFSET) // 0x4002 0000
#define RCC_BASE            (AHB1_BASE + RCC_OFFSET) // 0x4002 3800
#define GPIO_BASE           (AHB1_BASE)
/*REGISTER*/
#define GPIOB               (GPIO_BASE + GPIOB_OFFSET)

/* Define GPIO*/
#define GPIO(bank)  ((struct gpio*)((GPIO_BASE + 0x400)*(bank))) // Cho phep lay dia chi cua cac GPIO: A,B,C
// Enum values are per datasheet : 0 , 1 , 2 , 3
enum{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
};
// Khai báo toàn bộ configure clock có trong stm32f411
struct rcc
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;

    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    uint32_t RESERVED0[2];

    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    uint32_t RESERVED1[2];

    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    uint32_t RESERVED2[2];

    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    uint32_t RESERVED3[2];

    volatile uint32_t RCC_AHB1LPENR;
    volatile uint32_t RCC_AHB2LPENR;
    uint32_t RESERVED4[2];

    volatile uint32_t RCC_APB1LPENR;
    volatile uint32_t RCC_APB2LPENR;
    uint32_t RESERVED5[2];

    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    uint32_t RESERVED6[2];

    volatile uint32_t RCC_SSCGR;
    volatile uint32_t RCC_PLLI2SCFGR;
    volatile uint32_t RESERVED7;
    volatile uint32_t RCC_DCKCFGR;
};
struct gpio {
    volatile uint32_t
        MODER,
        OTYPER,
        OSPEEDR,
        PUPDR,
        IDR,
        ODR,
        BSRR,
        LCKR,
        AFR[2];
};

static inline void gpio_set_mode(uint16_t pin,uint8_t mode)
{
    struct gpio* gpio = GPIO(PINBANK(pin)); // GPIO bank
    int n = PINNO(pin);                     // Pin number
    gpio->MODER &= ~(3U << (n*2));          // Clear existing setting
    gpio->MODER |= (mode & 3) << (n *2);    // Set new mode
 
}
extern void _estack(void);                                        
void main(void)
{
    uint32_t cnt = 0,half;
    while (1)
    {
        cnt +=2;
        half = cnt/2;
        ++half;
    }
    
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

