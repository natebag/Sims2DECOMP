// globs.cpp - Global game data
// From: u2_ngc_release_dvd\globs.obj
// Small functions (<=64 bytes) decompiled

#include "core/globs.h"

// External function declarations
extern "C" void* memset(void* dest, int val, unsigned int len);
extern "C" void __builtin_delete(void* ptr);

// Global instance - stored at r13-32060 (SDA)
Globs* globs;

// Static data
LightingParameters sLightingParameters; // 0x80485e38

// ============================================================================
// LightingParameters
// ============================================================================

// LightingParameters::LightingParameters(void) - 0x800b815c (56 bytes)
// NON_MATCHING - GCC tail-calls memset, original has explicit stack frame + bl memset + returns this
// Zeroes 68 bytes of data via memset
LightingParameters::LightingParameters(void) {
    memset(this, 0, 0x44);
}

// LightingParameters::~LightingParameters(void) - 0x800b8194 (40 bytes)
// NON_MATCHING - SN Systems generates r4&1 delete check; GCC generates just blr
LightingParameters::~LightingParameters(void) {
}

// ============================================================================
// Globs
// ============================================================================

// Globs::Globs(void) - 0x800b81bc (12 bytes)
// NON_MATCHING - original uses r13-relative (SDA), GCC uses absolute addressing
// Assembly: mr r0,r3; stw r0,-32060(r13); blr
Globs::Globs(void) {
    globs = this;
}

// Globs::~Globs(void) - 0x800b81c8 (48 bytes)
// NON_MATCHING - original uses r13-relative + r4&1 delete check; GCC omits frame+check
// Assembly: li r0,0; stw r0,-32060(r13); andi. r0,r4,1; beq skip; bl __builtin_delete
Globs::~Globs(void) {
    globs = 0;
}
