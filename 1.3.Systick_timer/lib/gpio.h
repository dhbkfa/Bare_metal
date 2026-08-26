#ifndef GPIO_H
#define GPIO_H
#include "stm32f4xx.h"
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
// Enum values are per datasheet : 0 , 1 , 2 , 3
enum{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
};
void gpio_write(uint16_t pin , bool val);
void spin(volatile uint32_t count);
void gpio_set_mode(uint16_t pin,uint8_t mode);
void blinkled(char GPIOx,const int pinx,uint8_t Mode);
#endif  