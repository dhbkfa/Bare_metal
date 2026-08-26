#ifndef GPIO_H
#define GPIO_H
#include "../../include/device/stm32f4xx.h"

void gpio_write(uint16_t pin , bool val);
void gpio_set_mode(uint16_t pin,uint8_t mode);
#endif  