// cheats.cpp - Cheats system
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(cheats.obj)
//
// Small functions (<=64 bytes) decompiled from the cheats object file.

#include "types.h"

//=============================================================================
// Cheats class
//=============================================================================
class Cheats {
public:
    u8 pad00[0x0C];
    void* m_data;  // 0x0C

    // Various cheat enable/disable stubs
    // Most are empty (just blr) or simple flag sets

    // GetCheatMode - returns cheat mode from nested data
    // Address: 0x8002193C, Size: 12
    int GetCheatMode() {
        void* data = *(void**)((u8*)this + 0x0C);
        return *(int*)((u8*)data + 0x50);
    }

    // Empty stubs (just blr)
    void CheatStub1() {}
    void CheatStub2() {}
};
