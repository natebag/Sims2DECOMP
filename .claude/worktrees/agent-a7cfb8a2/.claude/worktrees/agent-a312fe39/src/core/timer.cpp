// timer.cpp - Timer small functions
// From: timer.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/timer.h"

// ============================================================================
// SDA globals (r13-relative)
// ============================================================================
// These are stored in the small data area, accessed via r13 register.
// For matching, these must be placed in .sbss/.sdata by the linker script.
// The exact r13 offsets:
//   Timer_GetTime:       lfs f1, -0x6150(r13)
//   Timer_GetTotalTime:  lfs f1, -0x614C(r13)
//   Timer_GetTicks:      lwz r3, -0x6144(r13)
//   Timer_GetTotalTicks: lwz r3, -0x6140(r13)

// NON_MATCHING - All four functions below use SDA (r13-relative) addressing
// in the original binary. devkitPPC places static locals in .sbss/.sdata2
// using lis+lwz/lfs instead of r13-relative. Requires proper linker script
// to place these globals in the SDA range for matching.

extern float s_deltaTime;       // r13 - 0x6150
extern float s_totalTime;       // r13 - 0x614C
extern int s_deltaTicks;        // r13 - 0x6144
extern int s_totalTicks;        // r13 - 0x6140

// ============================================================================
// Timer_GetTime(void)
// 0x800770c4 - 8 bytes
// lfs f1, -0x6150(r13); blr
// ============================================================================
float Timer_GetTime(void) {
    return s_deltaTime;
}

// ============================================================================
// Timer_GetTotalTime(void)
// 0x800770cc - 8 bytes
// lfs f1, -0x614C(r13); blr
// ============================================================================
float Timer_GetTotalTime(void) {
    return s_totalTime;
}

// ============================================================================
// Timer_GetTicks(void)
// 0x800770d4 - 8 bytes
// lwz r3, -0x6144(r13); blr
// ============================================================================
int Timer_GetTicks(void) {
    return s_deltaTicks;
}

// ============================================================================
// Timer_GetTotalTicks(void)
// 0x800770dc - 8 bytes
// lwz r3, -0x6140(r13); blr
// ============================================================================
int Timer_GetTotalTicks(void) {
    return s_totalTicks;
}
