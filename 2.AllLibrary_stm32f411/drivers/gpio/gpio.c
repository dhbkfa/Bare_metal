#include "gpio.h"

void gpio_write(uint16_t pin , bool val)
{
    struct gpio* gpio = GPIO(PINBANK(pin));
    gpio->BSRR = (1U << PINNO(pin)) << (val ? 0 : 16);
    
}
// Tham so truyen vao la PIN va che do can xet 
void gpio_set_mode(uint16_t pin,uint8_t mode)
{
    struct gpio* gpio = GPIO(PINBANK(pin)); // GPIO bank
    int n = PINNO(pin);                     // Pin number
    gpio->MODER &= ~(3U << (n*2));          // Clear existing setting
    gpio->MODER |= (mode & 3) << (n *2);    // Set new mode
 
}
void gpio_set_af(uint16_t pin,uint8_t af)
{
    struct gpio* gpio = GPIO(PINBANK(pin)); // GPIO bank : da co dia chi cua GPIO can xet
    int n = PINNO(pin);                     // Pin number : da co so pin can xet
    /* Alternate function low 0-7 */
    if(n < 8)
    {
        gpio->AFRL &= ~(15U << (n * 4));     // Clear existing setting
        gpio->AFRL |= (uint32_t)af << (n * 4);      // Set new alternate function 
    }
    /* Alternate function high 8-15 */
    else 
    {
        gpio->AFRH &= ~(15U << ((n-8) << (n*4)));   // Clear existing setting
        gpio->AFRH |= (uint32_t)af << ((n-8) * 4) ; // Set new alternate function 
    }
    

}
