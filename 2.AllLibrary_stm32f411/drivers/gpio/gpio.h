#ifndef GPIO_H
#define GPIO_H
#include "../../include/device/stm32f4xx.h"

void gpio_write(uint16_t pin , bool val);
void gpio_set_mode(uint16_t pin,uint8_t mode);
/* Định nghĩa các thanh ghi cho gpio */
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
/* Define GPIO*/
#define GPIO(bank)  ((struct gpio*)((GPIO_BASE + (0x400*bank)))) // Cho phep lay dia chi cua cac GPIO: A,B,C

#endif  