// ctgmicrotimer_ngc.cpp - CTG micro timer NGC implementation
// From: ctgmicrotimer_ngc.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/ctgmicrotimer.h"

// ============================================================================
// QueryPerformanceFrequency(long long *)
// 0x8007d6a8 - 24 bytes
// NGC implementation of Win32-style QueryPerformanceFrequency
// Returns the bus clock frequency: 0x00003F0D = 16141
// Original: li r9,0; li r10,0x3F0D; stw r9,0(r3); stw r10,4(r3); li r3,1; blr
// ============================================================================
// NON_MATCHING - Register allocation differs. Original uses r9/r10, GCC uses r10/r11.
int QueryPerformanceFrequency(long long* frequency) {
    *frequency = 0x3F0D;
    return 1;
}
