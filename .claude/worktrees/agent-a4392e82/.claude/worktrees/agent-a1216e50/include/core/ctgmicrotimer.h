#ifndef CTGMICROTIMER_H
#define CTGMICROTIMER_H

#include "types.h"

// QueryPerformanceFrequency - NGC implementation
// From: ctgmicrotimer_ngc.obj
// Returns the bus clock frequency (16141 = 0x3F0D)
// Mimics Win32 API signature for cross-platform compatibility
int QueryPerformanceFrequency(long long* frequency);

#endif // CTGMICROTIMER_H
