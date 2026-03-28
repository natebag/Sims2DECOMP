#if 0 // SKIP
// eorhouse.cpp - EHouse (house management)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(eorhouse.obj)
//
// Small functions (<=64 bytes) decompiled from the eorhouse object file.

#include "types.h"
#include "stub_classes.h"

// External functions
extern void* UIStringLookup_GetString(int id);

//=============================================================================
// EHouse
//=============================================================================
class EHouse {
public:
    u8 pad00[0x40];

    // GetHouseName
    // Address: 0x800236F8, Size: 36
    // NON_MATCHING - delegates to global function with member
    const char* GetHouseName();

    // Init
    // Address: 0x800239EC, Size: 52
    // NON_MATCHING - complex initialization
    void Init();

    // SetWallState
    // Address: 0x80023BAC, Size: 52
    // NON_MATCHING - flag manipulation
    void SetWallState(int state);

    // Refresh
    // Address: 0x800254A8, Size: 40
    // NON_MATCHING - render refresh
    void Refresh();

    // TriggerLightningEffect - empty stub
    // Address: 0x80024824, Size: 4
    void TriggerLightningEffect() {}

    // GetRoomAmbLight - returns indexed ambient light
    // Address: 0x8002539C, Size: 16
    // NON_MATCHING - indexed array access
    void* GetRoomAmbLight(int idx);
};

//=============================================================================
// GetHouseNameText - global function
// Address: 0x800236C8, Size: 48
// NON_MATCHING - string lookup
//=============================================================================
const char* GetHouseNameText(int id);
#endif
