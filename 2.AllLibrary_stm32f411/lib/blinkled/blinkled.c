#include "blinkled.h"

void blinkled(char GPIOx,const int pinx,uint8_t Mode,const uint32_t period_ms)
{
    uint16_t led = PIN(GPIOx,pinx);
    RCC->AHB1ENR |= BIT(PINBANK(led));
    gpio_set_mode(led,Mode);
    bool led_state = false;
    uint32_t now = s_ticks;
    uint32_t next_blink = now + period_ms;
    while (true)
    {
        now = s_ticks;
        if (now >= next_blink)
        {
            gpio_write(led,led_state);
            led_state = !led_state;
            next_blink += period_ms;
        }
        
    }
    
    // for (;;)
    // {
    //     gpio_write(led,true);
    //     spin(999999);
    //     gpio_write(led,false);
    //     spin(999999);
    // }
}

