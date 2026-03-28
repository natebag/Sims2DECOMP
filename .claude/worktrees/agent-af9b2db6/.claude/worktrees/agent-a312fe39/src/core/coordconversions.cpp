// coordconversions.cpp - Coordinate conversion small functions
// From: coordconversions.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/coordconversions.h"

// ============================================================================
// External references
// ============================================================================

// Scale factors stored as float constants in .sdata2
// At 0x803d9054 (r2-relative): AltToWorld scale factor
// At 0x803d9058 (r2-relative): WorldToAlt inverse scale factor
// These are likely 1/sqrt(2) type constants for iso-to-world conversion
static const float kAltToWorldScale = 0.5f;       // TODO: verify exact value from .sdata2
static const float kWorldToAltScale = 2.0f;        // TODO: verify exact value from .sdata2

// ============================================================================
// AltToWorld(float &)
// 0x800a4a84 - 44 bytes
// Converts altitude to world by calling AltToIso then scaling
// ============================================================================
// NON_MATCHING - Uses float constants from .sdata2 section whose exact values
// need to be extracted from the binary. The structure is correct:
// calls AltToIso(val), then multiplies result by scale factor.
float AltToWorld(float& val) {
    float result = AltToIso(val);
    return result * kAltToWorldScale;
}

// ============================================================================
// WorldToAlt(float &)
// 0x800a4ab0 - 56 bytes
// Converts world to altitude by scaling then calling IsoToAlt
// ============================================================================
// NON_MATCHING - Uses float constant from .sdata2 section whose exact value
// needs to be extracted. The structure is correct:
// multiplies input by inverse scale, stores to stack local, calls IsoToAlt.
float WorldToAlt(float& val) {
    float scaled = val * kWorldToAltScale;
    return IsoToAlt(scaled);
}
