
#include "../lib/blinkled/blinkled.h"
#include "../drivers/system/system.h"
                                     
void main(void)
{
    
    system_clock_init();
    systick_init(SYS_FREQUENCY);
    blinkled('C',13,GPIO_MODE_OUTPUT,500);
    //blinkled('B',8,GPIO_MODE_OUTPUT,500);

    while (1);

    
    
    
}
