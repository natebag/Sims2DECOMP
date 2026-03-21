// e_ngcengine.cpp - ENgcEngine (GameCube engine core)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(e_ngcengine.obj)
//
// Small functions (<=64 bytes) decompiled from the e_ngcengine object file.
// ENgcEngine is the top-level engine object managing init/update/render.

#include "types.h"

// Forward declarations
class EController;

// External functions
extern void* EAHeap_GetCurrentHeap();
extern void* EAHeap_Alloc(void* heap, u32 size, int align);
extern void EAHeap_Free(void* heap, void* ptr);

//=============================================================================
// ENgcEngine - GameCube engine class
//=============================================================================
class ENgcEngine {
public:
    u8 pad00[0x80]; // Lots of members

    // Many small functions are simple getters/setters
    // Most delegate to parent EEngine or access member fields

    // operator new
    static void* operator new(unsigned int size) {
        void* heap = EAHeap_GetCurrentHeap();
        return EAHeap_Alloc(heap, size, 0);
    }

    // operator delete
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }
};

//=============================================================================
// EController stubs from e_ngcengine.obj
//=============================================================================

// EController::IsPluggedIn - returns true
// Many controller functions are simple field reads
