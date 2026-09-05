#ifndef FLASH_H

#define FLASH_H
#include "../../include/cores/arm_cortex_m4.h"
/* The register control flash */
struct flash
{
    volatile uint32_t ACR;          // Access control register
    volatile uint32_t KEYR;         // Key register
    volatile uint32_t OPTKEYR;      // Option key register 
    volatile uint32_t SR;           // Status register
    volatile uint32_t CR;           // Control register
    volatile uint32_t OPTCR;        // Option control register


};
#define FLASH ((struct flash*) FLASH_BASE)

#endif