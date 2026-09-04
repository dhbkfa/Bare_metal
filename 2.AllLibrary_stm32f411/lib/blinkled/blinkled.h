#ifndef BLINKLED_H
#define BLINKLED_H
#include "../../drivers/gpio/gpio.h"
#include "../../include/device/stm32f4xx.h"
#include "../../drivers/systick/systick.h"


void blinkled(char GPIOx,const int pinx,uint8_t Mode,const uint32_t period_ms);


#endif