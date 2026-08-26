#ifndef ARM_CORTEX_M4_H
#define ARM_CORTEC_M4_H
#include "../include_common.h"


// Define all peripheral
/* INTERNAL BASE*/
#define Internal_BASE   	(0xE0000000UL)



// OFFSET ADDRESS

#define Systick_OFFSET	    (0x0000E010UL)


/*REGISTER*/

#define Systick_Timer	    (Internal_BASE + Systick_OFFSET)
/* Define GPIO*/

#define SYSTICK     ((struct systick*) Systick_Timer) // Cho phep lay cac thanh ghi cau hinh trong systick

// Declare the systicks in the system
struct systick{
	volatile uint32_t CSR,RVR,
		          CVR,CALIB;
};


#endif