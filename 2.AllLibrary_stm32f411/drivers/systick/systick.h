#ifndef SYSTICK_H
#define SYSTICK_H
#include "../../include/cores/arm_cortex_m4.h"
extern volatile uint32_t s_ticks;
void systick_init(uint32_t tick_hz);
void SysTick_Handler(void);
// Declare the systicks in the system for peropheral structure
struct systick{
	union  // Control and status register
	{
		volatile uint32_t CSR;
		struct 
		{
			volatile uint32_t ENABLE : 1; 		// Counter enable
			volatile uint32_t TICKINT : 1;		// Systick exception request enable
			volatile uint32_t CLKSOURCE : 1;	// Clock source [0: AHB/8, 1: Processor clock]
			volatile uint32_t : 13;				// Reserved
			volatile uint32_t COUNTFLAG : 1;	// Returns 1 if timer counted to 8 since last read
			volatile uint32_t : 15;
		}CSR_b; // bit field
	};
	union // Reload value register 
	{
		volatile uint32_t RVR;
		struct 
		{
			volatile uint32_t RELOAD : 24;		// Value to load into the CVR 
			volatile uint32_t : 8;				// Reserved
		}RVR_b;
		
	};
	union // Current value register
	{
		volatile uint32_t CVR;
		struct 
		{
			volatile uint32_t CURRENT : 32;			// Reads or clears the current counter value
		}CVR_b;
		
	};
	union // Calibration value Register
	{
		volatile uint32_t CALIB;
		struct 
		{
			volatile uint32_t TENMS : 24;			// Holds a reload value to be used for 10ms(100hz)
			volatile uint32_t : 6; 					// Reserved
			volatile uint32_t SKEW : 1;				// Indicates whether the 10ms calibration value is exact
			volatile uint32_t NOREF : 1;			// Indicates whether the IMPLEMENTATION DEFINED reference clock is implemented
		}CALIB_b;
		
	};
	
	
};

#define SYSTICK     ((struct systick*) Systick_Timer) // Cho phep lay cac thanh ghi cau hinh trong systick


#endif