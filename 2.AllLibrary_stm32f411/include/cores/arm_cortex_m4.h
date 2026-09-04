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

#define SYSTICK     ((struct systick*) Systick_Timer) // Cho phep lay cac thanh ghi cau hinh trong systick

// Declare the systicks in the system
struct systick{
	volatile uint32_t CSR,RVR,
		          CVR,CALIB;
};

/* SCB (System control block) Register map */
struct scb
{
    volatile uint32_t CPUID;       // CPU ID base register
    volatile uint32_t ICSR;        // Interrupt control and state register
    volatile uint32_t VTOR;        // Vector table offset register
    volatile uint32_t AIRCR;       // Application interrupt and reset control register
    volatile uint32_t SCR;         // System control register
    volatile uint32_t CCR;         // Configuration and control register
    volatile uint8_t  SHP[12];     // System handler priority registers
    volatile uint32_t SHCSR;       // System handler control and state register
    volatile uint32_t CFSR;        // Configurable fault status register
    volatile uint32_t HFSR;        // Hard fault status register
    volatile uint32_t DFSR;        // Debug fault status register
    volatile uint32_t MMFAR;       // MemManage fault address register
    volatile uint32_t BFAR;        // BusFault address register
    volatile uint32_t AFSR;        // Auxiliary fault status register
    volatile uint32_t RES[12];     // Padding
    volatile uint32_t CPACR;       // Coprocessor access control register (for FPU)
};
#define SCB     ((struct scb*) SCB_ADDRESS)

#endif