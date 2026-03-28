// comeseeme.cpp - Decompiled small functions from comeseeme.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\comeseeme.obj
//
// 2 small functions (<=64 bytes) decompiled

#include "objects/comeseeme.h"

// ============================================================================
// GetComeSeeMeSelector
// Address: 0x800B3CB4, Size: 64 bytes
// NON_MATCHING - virtual call dispatch pattern (blrl vs bctr)
// Gets the ComeSeeMeSelector from global pointer via virtual call
// The virtual call loads vtable, gets offset and function pointer
// ============================================================================
ObjSelector* GetComeSeeMeSelector() {
    // g_pComeSeeMeSelector is at SDA r13-21508
    // Loads vtable from *g_pComeSeeMeSelector, calls virtual method
    // with hash 0xF3AAA62F as parameter
    // Virtual call: vtable[0] + offset at vtable[0x78], function at vtable[0x7C]
    void** obj = (void**)g_pComeSeeMeSelector;
    void** vtable = (void**)*obj;
    // vtable dispatch: offset at [0x78/4=30], func at [0x7C/4=31]
    int offset = *(short*)((u8*)vtable + 0x78);
    void* func = *(void**)((u8*)vtable + 0x7C);
    typedef ObjSelector* (*VirtualFunc)(void*, unsigned int);
    return ((VirtualFunc)func)((u8*)obj + offset, 0xF3AAA62F);
}

// ============================================================================
// FTilePt::operator==
// Address: 0x803A2FF8, Size: 48 bytes
// NON_MATCHING - bool conversion pattern (xor + subfic/adde)
// Compares two FTilePt positions
// ============================================================================
bool FTilePt::operator==(FTilePt& other) const {
    if (m_y != other.m_y) return false;
    return (m_x == other.m_x);
}
