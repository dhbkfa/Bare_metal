#ifndef FLASH_H

#define FLASH_H
#include "../../include/cores/arm_cortex_m4.h"
/* The register control flash */
struct flash
{
    /* ============================================================
     * FLASH Access Control Register
     * ============================================================ */
    union
    {
        volatile uint32_t ACR;
        struct
        {
            volatile uint32_t LATENCY  : 4;    // Flash access latency
            volatile uint32_t          : 4;    // Reserved
            volatile uint32_t PRFTEN   : 1;    // Prefetch enable
            volatile uint32_t ICEN     : 1;    // Instruction cache enable
            volatile uint32_t DCEN     : 1;    // Data cache enable
            volatile uint32_t ICRST    : 1;    // Instruction cache reset
            volatile uint32_t DCRST    : 1;    // Data cache reset
            volatile uint32_t          : 19;   // Reserved
        } ACR_b;

    };


    /* ============================================================
     * FLASH Key Register
     * ============================================================ */
    union
    {
        volatile uint32_t KEYR;

        struct
        {
            volatile uint32_t KEY : 32;        // Key used to unlock FLASH control
        } KEYR_b;

    };


    /* ============================================================
     * FLASH Option Key Register
     * ============================================================ */
    union
    {
        volatile uint32_t OPTKEYR;

        struct
        {
            volatile uint32_t OPTKEY : 32;     // Key used to unlock option bytes
        } OPTKEYR_b;

    };


    /* ============================================================
     * FLASH Status Register
     * ============================================================ */
    union
    {
        volatile uint32_t SR;

        struct
        {
            volatile uint32_t EOP     : 1;     // End of operation
            volatile uint32_t OPERR   : 1;     // Operation error
            volatile uint32_t         : 2;     // Reserved
            volatile uint32_t WRPERR  : 1;     // Write protection error
            volatile uint32_t PGAERR  : 1;     // Programming alignment error
            volatile uint32_t PGPERR  : 1;     // Programming parallelism error
            volatile uint32_t PGSERR  : 1;     // Programming sequence error
            volatile uint32_t         : 8;     // Reserved
            volatile uint32_t BSY     : 1;     // FLASH busy
            volatile uint32_t         : 15;    // Reserved
        } SR_b;

    };


    /* ============================================================
     * FLASH Control Register
     * ============================================================ */
    union
    {
        volatile uint32_t CR;

        struct
        {
            volatile uint32_t PG      : 1;     // Programming activation
            volatile uint32_t SER     : 1;     // Sector erase activation
            volatile uint32_t MER     : 1;     // Mass erase activation
            volatile uint32_t SNB     : 4;     // Sector number
            volatile uint32_t PSIZE   : 2;     // Program size
            volatile uint32_t         : 6;     // Reserved
            volatile uint32_t STRT    : 1;     // Start erase operation
            volatile uint32_t         : 7;     // Reserved
            volatile uint32_t EOPIE   : 1;     // End of operation interrupt enable
            volatile uint32_t ERRIE   : 1;     // Error interrupt enable
            volatile uint32_t         : 5;     // Reserved
            volatile uint32_t LOCK    : 1;     // FLASH control register lock
        } CR_b;

    };


    /* ============================================================
     * FLASH Option Control Register
     * ============================================================ */
    union
    {
        volatile uint32_t OPTCR;

        struct
        {
            volatile uint32_t OPTLOCK     : 1; // Option bytes lock
            volatile uint32_t OPTSTRT     : 1; // Start option byte programming
            volatile uint32_t BOR_LEV     : 2; // Brown-out reset level
            volatile uint32_t             : 1; // Reserved
            volatile uint32_t WDG_SW      : 1; // Software/hardware watchdog selection
            volatile uint32_t nRST_STOP   : 1; // Reset generated in Stop mode
            volatile uint32_t nRST_STDBY  : 1; // Reset generated in Standby mode
            volatile uint32_t RDP         : 8; // Read protection level
            volatile uint32_t nWRP        : 12;// Write protection for sectors
            volatile uint32_t             : 3; // Reserved
            volatile uint32_t SPRMOD      : 1; // Sector protection mode
        } OPTCR_b;

    };
};
#define FLASH ((struct flash*) FLASH_BASE)

#endif