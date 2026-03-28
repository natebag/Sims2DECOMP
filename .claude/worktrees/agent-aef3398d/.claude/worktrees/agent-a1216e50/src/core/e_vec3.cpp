// e_vec3.cpp - EVec2/EVec3 math functions
// From: base_ngc_release_dvd.lib(e_vec3.obj)
// Small functions (<=64 bytes) decompiled from this object

#include "core/e_vec3.h"

// External function declarations
extern "C" void EORDbgTrace(const char* fmt, ...);

// ============================================================================
// EVec2::Print - 0x802d5a34 (56 bytes)
// NON_MATCHING - original has stack frame (stwu/mflr), ours gets tail-call optimized
// Prints "x y\n" format using EORDbgTrace
// ============================================================================
void EVec2::Print(void) {
    EORDbgTrace("%f %f\n", x, y);
}

// ============================================================================
// EVec3::Print - 0x802d5a6c (60 bytes)
// NON_MATCHING - original has stack frame (stwu/mflr), ours gets tail-call optimized
// Prints "x y z\n" format using EORDbgTrace
// ============================================================================
void EVec3::Print(void) {
    EORDbgTrace("%f %f %f\n", x, y, z);
}

// ============================================================================
// EVec3::ToU8s - 0x802d5aa8 (120 bytes)
// NON_MATCHING - loop uses CTR on original, compiler generates different loop structure
// Converts vec3 floats to unsigned bytes [0,255], clamped
// ============================================================================
void EVec3::ToU8s(unsigned char* out) const {
    const float* src = &x;
    for (int i = 0; i < 3; i++) {
        float val = src[i] * 255.0f;
        if (val < 0.0f) {
            out[i] = 0;
        } else if (val > 255.0f) {
            out[i] = 255;
        } else {
            out[i] = (unsigned char)(int)val;
        }
    }
}

// ============================================================================
// EVec3::FromU8s - 0x802d5b20 (88 bytes)
// NON_MATCHING - loop counter uses CTR in original, compiler generates different loop
// Converts unsigned bytes [0,255] to vec3 floats [0,1]
// ============================================================================
void EVec3::FromU8s(unsigned char* in) {
    float* dst = &x;
    for (int i = 0; i < 3; i++) {
        dst[i] = (float)in[i] * (1.0f / 255.0f);
    }
}

// ============================================================================
// EVec3::ToS8s - 0x802d5b78 (120 bytes)
// NON_MATCHING - loop counter uses CTR in original, compiler generates different loop
// Converts vec3 floats to signed bytes [-127,127], clamped
// ============================================================================
void EVec3::ToS8s(signed char* out) const {
    const float* src = &x;
    for (int i = 0; i < 3; i++) {
        float val = src[i] * 127.0f;
        if (val < -127.0f) {
            out[i] = -127;
        } else if (val > 127.0f) {
            out[i] = 127;
        } else {
            out[i] = (signed char)(int)val;
        }
    }
}

// ============================================================================
// EVec3::FromS8s - 0x802d5bf0 (96 bytes)
// NON_MATCHING - loop counter uses CTR in original, compiler generates different loop
// Converts signed bytes [-127,127] to vec3 floats [-1,1]
// ============================================================================
void EVec3::FromS8s(signed char* in) {
    float* dst = &x;
    for (int i = 0; i < 3; i++) {
        dst[i] = (float)in[i] * (1.0f / 127.0f);
    }
}
