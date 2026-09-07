#ifndef SCB_H
#define SCB_H
#include "../../include/cores/arm_cortex_m4.h"
/* SCB (System control block) Register map */
struct scb
{
    union // CPU ID base register
    {
        volatile uint32_t CPUID;
        struct
        {
            volatile uint32_t REVISION : 4;  // Revision number
            volatile uint32_t PARTNO    : 12; // Part number
            volatile uint32_t           : 4;
            volatile uint32_t VARIANT   : 4;  // Variant number
            volatile uint32_t IMPLEMENTER: 8; // Implementer
        } CPUID_b;
    };

    union // Interrupt control and state register
    {
        volatile uint32_t ICSR;
        struct
        {
            volatile uint32_t VECTACTIVE : 9;  // Active exception number
            volatile uint32_t            : 2;
            volatile uint32_t RETOBASE   : 1;  // Return to base
            volatile uint32_t VECTPENDING: 9;  // Pending exception number
            volatile uint32_t            : 1;
            volatile uint32_t ISRPENDING : 1;  // External interrupt pending
            volatile uint32_t            : 2;
            volatile uint32_t PENDSTCLR  : 1;  // Clear SysTick pending
            volatile uint32_t PENDSTSET  : 1;  // Set SysTick pending
            volatile uint32_t PENDSVCLR  : 1;  // Clear PendSV pending
            volatile uint32_t PENDSVSET  : 1;  // Set PendSV pending
            volatile uint32_t NMIPENDSET : 1;  // Set NMI pending
        } ICSR_b;
    };

    union // Vector table offset register
    {
        volatile uint32_t VTOR;
        struct
        {
            volatile uint32_t           : 7;
            volatile uint32_t TBLOFF     : 25; // Vector table offset
        } VTOR_b;
    };

    union // Application interrupt and reset control register
    {
        volatile uint32_t AIRCR;
        struct
        {
            volatile uint32_t VECTRESET : 1;  // Vector reset
            volatile uint32_t VECTCLRACTIVE: 1; // Clear active state
            volatile uint32_t SYSRESETREQ: 1;  // System reset request
            volatile uint32_t            : 5;
            volatile uint32_t PRIGROUP  : 3;  // Priority grouping
            volatile uint32_t            : 4;
            volatile uint32_t ENDIANNESS: 1;  // Endianness
            volatile uint32_t VECTKEY   : 16; // Register key
        } AIRCR_b;
    };

    union // System control register
    {
        volatile uint32_t SCR;
        struct
        {
            volatile uint32_t            : 1;
            volatile uint32_t SLEEPONEXIT : 1; // Sleep on ISR exit
            volatile uint32_t SLEEPDEEP   : 1; // Deep sleep
            volatile uint32_t            : 1;
            volatile uint32_t SEVONPEND   : 1; // Event on pending
            volatile uint32_t            : 27;
        } SCR_b;
    };

    union // Configuration and control register
    {
        volatile uint32_t CCR;
        struct
        {
            volatile uint32_t NONBASETHRDENA : 1; // Thread mode from handler
            volatile uint32_t USERSETMPEND   : 1; // User can set pending
            volatile uint32_t                : 1;
            volatile uint32_t UNALIGN_TRP    : 1; // Trap unaligned access
            volatile uint32_t DIV_0_TRP      : 1; // Trap divide by zero
            volatile uint32_t                : 3;
            volatile uint32_t BFHFNMIGN      : 1; // Ignore BusFault in handlers
            volatile uint32_t STKALIGN       : 1; // Stack alignment
            volatile uint32_t                : 22;
        } CCR_b;
    };

    volatile uint8_t SHP[12]; // System handler priority registers

    union // System handler control and state register
    {
        volatile uint32_t SHCSR;
        struct
        {
            volatile uint32_t MEMFAULTACT  : 1; // MemManage active
            volatile uint32_t BUSFAULTACT  : 1; // BusFault active
            volatile uint32_t            : 1;
            volatile uint32_t USGFAULTACT  : 1; // UsageFault active
            volatile uint32_t            : 3;
            volatile uint32_t SVCALLACT    : 1; // SVCall active
            volatile uint32_t MONITORACT   : 1; // Debug monitor active
            volatile uint32_t            : 1;
            volatile uint32_t PENDSVACT    : 1; // PendSV active
            volatile uint32_t SYSTICKACT   : 1; // SysTick active
            volatile uint32_t USGFAULTPENDED: 1; // UsageFault pending
            volatile uint32_t MEMFAULTPENDED: 1; // MemManage pending
            volatile uint32_t BUSFAULTPENDED: 1; // BusFault pending
            volatile uint32_t SVCALLPENDED : 1; // SVCall pending
            volatile uint32_t MEMFAULTENA  : 1; // MemManage enable
            volatile uint32_t BUSFAULTENA  : 1; // BusFault enable
            volatile uint32_t USGFAULTENA  : 1; // UsageFault enable
            volatile uint32_t              : 13;
        } SHCSR_b;
    };

    union // Configurable fault status register
    {
        volatile uint32_t CFSR;
        struct
        {
            volatile uint32_t MMFSR : 8;  // MemManage fault status
            volatile uint32_t BFSR  : 8;  // BusFault status
            volatile uint32_t UFSR  : 16; // UsageFault status
        } CFSR_b;
    };

    union // Hard fault status register
    {
        volatile uint32_t HFSR;
        struct
        {
            volatile uint32_t            : 1;
            volatile uint32_t VECTTBL     : 1; // Vector table read fault
            volatile uint32_t            : 28;
            volatile uint32_t FORCED      : 1; // Forced HardFault
            volatile uint32_t DEBUGEVT    : 1; // Debug event
        } HFSR_b;
    };

    union // Debug fault status register
    {
        volatile uint32_t DFSR;
        struct
        {
            volatile uint32_t HALTED  : 1; // Halt request
            volatile uint32_t BKPT   : 1; // Breakpoint
            volatile uint32_t DWTTRAP : 1; // DWT match
            volatile uint32_t VCATCH : 1; // Vector catch
            volatile uint32_t EXTERNAL: 1; // External debug request
            volatile uint32_t         : 27;
        } DFSR_b;
    };

    union // MemManage fault address register
    {
        volatile uint32_t MMFAR;
        struct
        {
            volatile uint32_t ADDRESS : 32; // Fault address
        } MMFAR_b;
    };

    union // BusFault address register
    {
        volatile uint32_t BFAR;
        struct
        {
            volatile uint32_t ADDRESS : 32; // Fault address
        } BFAR_b;
    };

    union // Auxiliary fault status register
    {
        volatile uint32_t AFSR;
        struct
        {
            volatile uint32_t IMPDEF : 32; // Implementation defined
        } AFSR_b;
    };

    volatile uint32_t RES[12]; // Reserved

    union // Coprocessor access control register
    {
        volatile uint32_t CPACR;
        struct
        {
            volatile uint32_t         : 20;
            volatile uint32_t CP10    : 2; // Coprocessor 10 access
            volatile uint32_t CP11    : 2; // Coprocessor 11 access
            volatile uint32_t         : 8;
        } CPACR_b;
    };
};
#define SCB     ((struct scb*) SCB_ADDRESS)



#endif
