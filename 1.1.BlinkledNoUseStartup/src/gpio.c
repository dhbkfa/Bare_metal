#include "../lib/gpio.h"
#include "../lib/stm32f4xx.h"

void gpio_write(uint16_t pin , bool val)
{
    struct gpio* gpio = GPIO(PINBANK(pin));
    gpio->BSRR = (1U << PINNO(pin)) << (val ? 0 : 16);
    
}
void spin(volatile uint32_t count)
{
    while (count--)(void)0;
}
void gpio_set_mode(uint16_t pin,uint8_t mode)
{
    struct gpio* gpio = GPIO(PINBANK(pin)); // GPIO bank
    int n = PINNO(pin);                     // Pin number
    gpio->MODER &= ~(3U << (n*2));          // Clear existing setting
    gpio->MODER |= (mode & 3) << (n *2);    // Set new mode
 
}

void blinkled(char GPIOx,const int pinx,uint8_t Mode)
{
    uint16_t led = PIN(GPIOx,pinx);
    RCC->AHB1ENR |= BIT(PINBANK(led));
    gpio_set_mode(led,Mode);
    for (;;)
    {
        gpio_write(led,true);
        spin(999999);
        gpio_write(led,false);
        spin(999999);
    }
}