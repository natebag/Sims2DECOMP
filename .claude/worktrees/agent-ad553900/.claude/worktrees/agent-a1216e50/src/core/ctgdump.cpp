// ctgdump.cpp - CTGDump small functions
// From: ctgdump.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/ctgdump.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete - SN Systems runtime delete operator
extern "C" void __builtin_delete(void* ptr);

// __static_initialization_and_destruction_0 for this TU
extern "C" void __static_initialization_and_destruction_0_ctgdump(int init, int priority);

// ============================================================================
// localConvertToASCII(char *, unsigned wchar_t *)
// 0x800a5128 - 48 bytes
// Converts a wide (16-bit) string to ASCII by taking the low byte of each char
// Note: identical copy also exists in stringbuffer.obj
// ============================================================================
static void localConvertToASCII(char* dst, unsigned short* src) {
    while (*src != 0) {
        *dst = (char)*src;  // takes low byte
        dst++;
        src++;
    }
    *dst = 0;
}

// ============================================================================
// CTGDump::CTGDump(void)
// 0x800a5158 - 4 bytes
// Empty constructor (just blr)
// ============================================================================
CTGDump::CTGDump(void) {
    // empty
}

// ============================================================================
// CTGDump::~CTGDump(void)
// 0x800a515c - 40 bytes
// Destructor: conditionally calls __builtin_delete based on flag
// GCC virtual destructor pattern: if (flag & 1) __builtin_delete(this)
// ============================================================================
// NON_MATCHING - GCC generates the scalar deleting destructor pattern
// automatically. The flag parameter (r4) is the internal __in_charge parameter.
// Cannot manually replicate this; compiler generates it from ~CTGDump() definition.
CTGDump::~CTGDump(void) {
    // GCC auto-generates: if (__in_charge & 1) __builtin_delete(this);
}

// ============================================================================
// CTGDump::Shutdown(void)
// 0x800a5184 - 4 bytes
// No-op (just blr)
// ============================================================================
void CTGDump::Shutdown(void) {
    // empty
}

// ============================================================================
// CTGDump::operator<<(char *)
// 0x800a5188 - 4 bytes
// No-op (just blr) - release build strips all debug output
// ============================================================================
CTGDump& CTGDump::operator<<(char* str) {
    return *this;
}
