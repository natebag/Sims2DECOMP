// srand.cpp - Random number small functions
// From: srand.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/srand.h"

// ============================================================================
// SDA global: random seed
// r13 - 0x6008 = r13 - 24584
// ============================================================================
// NON_MATCHING (GetSRandSeed, SetSRandSeed) - SDA globals require linker script
// to place in r13-relative range. devkitPPC uses lis+lwz/stw instead.
extern unsigned int s_srandSeed;

// ============================================================================
// GetSRandSeed(void)
// 0x800a64e8 - 8 bytes
// lwz r3, -0x6008(r13); blr
// ============================================================================
unsigned int GetSRandSeed(void) {
    return s_srandSeed;
}

// ============================================================================
// SetSRandSeed(unsigned int)
// 0x800a64f0 - 8 bytes
// stw r3, -0x6008(r13); blr
// ============================================================================
void SetSRandSeed(unsigned int seed) {
    s_srandSeed = seed;
}

// ============================================================================
// RangedRandInt(unsigned int)
// 0x800a6544 - 56 bytes
// Returns a random integer in range [0, range)
// Uses rand() then takes modulo
// ============================================================================
// NON_MATCHING - Register allocation differs (r30/stmw vs r31/stw).
// Original uses stmw r30 / lmw r30 to save r30, GCC uses stw r31 / lwz r31.
// Original: divwu r0,r3,r30 / mullw r0,r0,r30 / subf r3,r0,r3
// GCC:      divwu r9,r3,r31 / mullw r9,r9,r31 / subf r3,r9,r3
unsigned int RangedRandInt(unsigned int range) {
    unsigned int r = (unsigned int)rand();
    return r % range;
}
