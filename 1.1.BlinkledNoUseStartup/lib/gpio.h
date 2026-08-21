#ifndef GPIO_H
#define GPIO_H
#include "stm32f4xx.h"
void gpio_write(uint16_t pin , bool val);
void spin(volatile uint32_t count);
void gpio_set_mode(uint16_t pin,uint8_t mode);
void blinkled(char GPIOx,const int pinx,uint8_t Mode);
#endif  