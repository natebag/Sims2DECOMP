// eyetoyclient.cpp - EyeToyClient (camera peripheral support)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(eyetoyclient.obj)
//
// Small functions (<=64 bytes) decompiled from the eyetoyclient object file.
// EyeToyClient manages the EyeToy camera peripheral interface.

#include "types.h"
#include "stub_classes.h"

//=============================================================================
// EyeToyClient
//=============================================================================
class EyeToyClient {
public:
    u8 pad00[0x80];

    // SaveComplete - empty stub
    // Address: 0x80037650, Size: 4
    void SaveComplete(int sectionID, void* saveRecord) {}

    // LoadComplete - empty stub
    // Address: 0x80037654, Size: 4
    void LoadComplete(int sectionID, void* loadRecord) {}

    // GetBrightness
    // Address: 0x80039434, Size: 24
    // NON_MATCHING - sdata access pattern
    float GetBrightness();

    // GetHue
    // Address: 0x80039378, Size: 56
    // NON_MATCHING - float conversion pattern
    float GetHue();

    // GetSaturation
    // Address: 0x8003932C, Size: 24
    // NON_MATCHING - sdata access pattern
    float GetSaturation();

    // SetBrightness
    // Address: 0x8003944C, Size: 52
    // NON_MATCHING - float range clamping
    void SetBrightness(float val);

    // Most of the 77 small functions in eyetoyclient are:
    // - Getters/setters accessing sdata/sbss globals
    // - Empty virtual stubs (blr)
    // - Simple flag toggles
};
