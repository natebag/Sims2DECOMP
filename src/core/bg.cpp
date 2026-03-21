// bg.cpp - Background loading (BG) system
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(bg.obj)
//
// Small functions (<=64 bytes) decompiled from the bg object file.
// BG handles background loading stages during game startup/transitions.

#include "types.h"

// External functions
extern void BG_ExecuteState(const char* name);
extern void BG_CompleteCallback(void* ctx, void* fn);

// Globals
extern int BG_s_bBGComplete;

//=============================================================================
// BGExec_LoadDefaultNeighborhood
// Address: 0x80014B9C, Size: 48
// NON_MATCHING - sdata string ref + function call
//=============================================================================
void BGExec_LoadDefaultNeighborhood() {
    BG_ExecuteState("LoadDefaultNeighborhood");
    BG_s_bBGComplete = 1;
}

//=============================================================================
// Other BG exec functions follow similar patterns:
// Each calls BG_ExecuteState with a different string, some set flags
//=============================================================================

// BGExec_CurHouseInit
// Address: 0x80014CB4, Size: 48
// NON_MATCHING - sdata refs
void BGExec_CurHouseInit();

// BGExec_FlushResQueue
// Address: 0x80014D2C, Size: 64
// NON_MATCHING - sdata refs
void BGExec_FlushResQueue();

// BGExec_SetCurHouse
// Address: 0x80014DB4, Size: 52
// NON_MATCHING - sdata refs
void BGExec_SetCurHouse();

// BGCall_SetGameModeAndResumeSounds
// Address: 0x80014E30, Size: 48
// NON_MATCHING - sdata refs
void BGCall_SetGameModeAndResumeSounds();

// BGExec_ReloadObjectQuickdata
// Address: 0x80014F00, Size: 48
// NON_MATCHING - sdata refs
void BGExec_ReloadObjectQuickdata();

// BGExec_CASCGEGenerateStage
// Address: 0x80014F78, Size: 56
// NON_MATCHING - sdata refs
void BGExec_CASCGEGenerateStage();
