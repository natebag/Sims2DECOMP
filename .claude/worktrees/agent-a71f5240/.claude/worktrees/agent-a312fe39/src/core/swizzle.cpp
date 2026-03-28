// swizzle.cpp - Data byte-swizzling small functions
// From: swizzle.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/swizzle.h"

// ============================================================================
// Swizzle2(void *)
// 0x800A7E64 - 20 bytes
// Swaps the first two bytes of a 16-bit value in place (byte-swap / endian swap)
// ============================================================================
// lbz r0,0(r3); lbz r9,1(r3); stb r0,1(r3); stb r9,0(r3); blr
// NON_MATCHING - GCC optimizes to sthbrx; original uses manual byte loads/stores
void Swizzle2(void* data) {
    volatile unsigned char* p = (volatile unsigned char*)data;
    unsigned char tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
}
