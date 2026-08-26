#include "../lib/blinkled.h"

void blinkled(char GPIOx,const int pinx,uint8_t Mode,float frequency)
{
    uint16_t led = PIN(GPIOx,pinx);
    RCC->AHB1ENR |= BIT(PINBANK(led));
    gpio_set_mode(led,Mode);
    bool led_state = false;
    uint32_t now = 0, next_blink = 500;
    systick_init(frequency);
    while (true)
    {
        now = s_ticks;
        if (now >= next_blink)
        {
            gpio_write(led,led_state);
            led_state = !led_state;
            next_blink = now + 500;
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

