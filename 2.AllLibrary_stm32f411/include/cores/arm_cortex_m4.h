#ifndef ARM_CORTEX_M4_H
#define ARM_CORTEX_M4_H
#include "../include_common.h"


// Define all peripheral
/* INTERNAL BASE*/
#define Internal_BASE   	(0xE0000000UL)



// OFFSET ADDRESS

#define Systick_OFFSET	    (0x0000E010UL)
#define SCB_OFFSET          (0x0000ED00UL)

/*REGISTER*/

#define Systick_Timer	    (Internal_BASE + Systick_OFFSET)
#define SCB_ADDRESS                (Internal_BASE + SCB_OFFSET)
/* Define GPIO*/


#endif