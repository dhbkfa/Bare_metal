#ifndef BLINKLED_H
#define BLINKLED_H
#include "gpio.h"
#include "stm32f4xx.h"
#include "systick.h"

void blinkled(char GPIOx,const int pinx,uint8_t Mode);


#endif