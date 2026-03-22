// ewallutil.cpp - EWallUtil (wall utility functions)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(ewallutil.obj)
//
// Small functions (<=64 bytes) decompiled from the ewallutil object file.

#include "types.h"
#include "stub_classes.h"

// Lookup tables
extern int g_wallTypeIds[6];      // at 0x80423A94
extern void* g_wallTypeLookup;    // at sdata

//=============================================================================
// GetWallTypeIndex - find wall type index from ID
// Address: 0x800371C4, Size: 60
//=============================================================================
int GetWallTypeIndex(int id) {
    for (int i = 0; i < 6; i++) {
        if (g_wallTypeIds[i] == id) return i;
    }
    return -1;
}

//=============================================================================
// GetWallShader - get shader from wall type index
// Address: 0x800371FC, Size: 32
// NON_MATCHING - double indirection through sdata global
//=============================================================================
void* GetWallShader(int index);

//=============================================================================
// GetWallFloorMask - get floor mask from wall type index
// Address: 0x80037228, Size: 28
// NON_MATCHING - double indirection through sdata global
//=============================================================================
int GetWallFloorMask(int index);
