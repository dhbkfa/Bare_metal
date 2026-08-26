
#include "../lib/blinkled/blinkled.h"

                                     
void main(void)
{
    systick_init(16000000);
    blinkled('C',13,GPIO_MODE_OUTPUT,500);
    return;
    
}
