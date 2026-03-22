// effectsfunctions.cpp - Effects namespace functions
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(effectsfunctions.obj)
//
// Small functions (<=64 bytes) decompiled from the effectsfunctions object file.
// Effects namespace contains particle/visual effect utility functions.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERC;
class EMat4;
class FastAllocPool;
struct EVec4 { float x, y, z, w; };

// External functions
extern void* EAHeap_GetCurrentHeap();
extern void EAHeap_Free(void* heap, void* ptr);
extern void* FastAllocPool_GetPool();

namespace Effects {

// GetDefaultRenderContext
// Address: 0x8035220C, Size: 8
// Returns a global render context pointer
void* GetDefaultRenderContext() {
    // Returns sdata global
    // NON_MATCHING - sdata access
    return 0;
}

// GetFaceCameraRotation - empty stub
// Address: 0x80352214, Size: 4
void GetFaceCameraRotation(ERC*, EMat4&, EVec4&, bool) {}

// GetTextureFromID
// Address: 0x803521E0, Size: 44
// NON_MATCHING - hash table lookup
void* GetTextureFromID(unsigned int id);

// FreeFastAllocPool
// Address: 0x80352218, Size: 64
// NON_MATCHING - pool free pattern
void FreeFastAllocPool(FastAllocPool* pool);

} // namespace Effects
