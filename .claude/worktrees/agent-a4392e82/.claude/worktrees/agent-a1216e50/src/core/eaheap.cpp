// eaheap.cpp - EAHeap, FPHeap, and global heap accessor functions
// From: base_ngc_release_dvd.lib(e_standard_heap.obj)
// Small functions (<=64 bytes) decompiled from this object

#include "core/eaheap.h"

// External functions called by these implementations
extern "C" void __register_atexit(void (*func)(void));

// SDA globals
extern int g_currentCheckPoint;

// Forward declarations for internal functions not in our small set
extern void* EAHeap_MallocInternal(EAHeap* heap, unsigned int size, int align);
extern void EAHeap_FreeInternal(EAHeap* heap, void* ptr);

// ============================================================================
// AllocPoolManager<ProtectedAllocPool>::Validate - 0x803c22b4 (64 bytes)
// Iterates 8 pools, calling Validate on each (stride = 52 = 0x34)
// Must be defined before ValidatePools() to avoid implicit instantiation
// ============================================================================
// NON_MATCHING - loop structure may differ
template<>
void AllocPoolManager<ProtectedAllocPool>::Validate(void) {
    ProtectedAllocPool* pool = (ProtectedAllocPool*)m_poolData;
    for (int i = 8; i > 0; i--) {
        pool->Validate();
        pool = (ProtectedAllocPool*)((char*)pool + 0x34);
    }
}

// ============================================================================
// AllocPoolManager<FastAllocPool>::Validate - 0x803c2408 (64 bytes)
// Iterates 8 pools, calling Validate on each (stride = 24 = 0x18)
// ============================================================================
// NON_MATCHING - loop structure may differ
template<>
void AllocPoolManager<FastAllocPool>::Validate(void) {
    FastAllocPool* pool = (FastAllocPool*)m_poolData;
    for (int i = 8; i > 0; i--) {
        pool->Validate();
        pool = (FastAllocPool*)((char*)pool + 0x18);
    }
}

// ============================================================================
// EAHeap::GetCurrentCheckPoint - 0x802d09d4 (8 bytes)
// Loads g_currentCheckPoint from SDA (r13-relative)
// ============================================================================
int EAHeap::GetCurrentCheckPoint(void) {
    return g_currentCheckPoint;
}

// ============================================================================
// EAHeap::SetNextCheckPoint - 0x802d09ac (40 bytes)
// Increments the global checkpoint counter
// ============================================================================
void EAHeap::SetNextCheckPoint(void) {
    g_currentCheckPoint = GetCurrentCheckPoint() + 1;
}

// ============================================================================
// EAHeap::ValidatePools - 0x802d0fa0 (36 bytes)
// Validates ProtectedAllocPool pools via AllocPoolManager
// Calls AllocPoolManager<ProtectedAllocPool>::Validate through SDA pointer
// ============================================================================
// NON_MATCHING - needs SDA-relative access to pool manager pointer
void EAHeap::ValidatePools(void) {
    AllocPoolManager<ProtectedAllocPool>* mgr = s_poolBlocks;
    mgr->Validate();
}

// ============================================================================
// FPHeap::FPHeap - 0x802d0fc4 (48 bytes)
// Constructor: calls EAHeap constructor (base), returns this
// Original just tail-calls the base constructor (already done by C++ semantics)
// ============================================================================
// NON_MATCHING - C++ compiler handles base class construction differently
FPHeap::FPHeap(char* name, void* buffer, unsigned int size, EAHeap* parent, EAHeap* auxHeap)
    : EAHeap(name, buffer, size, parent, auxHeap) {
}

// ============================================================================
// FPHeap::ValidatePools - 0x802d10c4 (36 bytes)
// Same pattern as EAHeap::ValidatePools but for FastAllocPool pools
// ============================================================================
// NON_MATCHING - needs SDA-relative access to pool manager pointer
void FPHeap::ValidatePools(void) {
    // Uses a different SDA slot for FastAllocPool pool manager
    // AllocPoolManager<FastAllocPool>* mgr = s_fpPoolBlocks;
    // mgr->Validate();
}

// ============================================================================
// DefaultFree - 0x802d1138 (52 bytes)
// Frees memory through MainHeap
// ============================================================================
void DefaultFree(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}

// ============================================================================
// __builtin_new - 0x802d11b0 (56 bytes)
// C++ operator new - allocates through MainHeap with no alignment
// ============================================================================
void* __builtin_new(unsigned int size) {
    EAHeap* heap = MainHeap();
    return heap->Malloc(size, 0);
}

// ============================================================================
// __builtin_vec_new - 0x802d11e8 (56 bytes)
// C++ operator new[] - identical to __builtin_new
// ============================================================================
void* __builtin_vec_new(unsigned int size) {
    EAHeap* heap = MainHeap();
    return heap->Malloc(size, 0);
}

// ============================================================================
// __builtin_delete - 0x802d1220 (52 bytes)
// C++ operator delete - frees through MainHeap
// ============================================================================
void __builtin_delete(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}

// ============================================================================
// __builtin_vec_delete - 0x802d1254 (52 bytes)
// C++ operator delete[] - identical to __builtin_delete
// ============================================================================
void __builtin_vec_delete(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}

// ============================================================================
// malloc - 0x802d1288 (56 bytes)
// C malloc - allocates through MainHeap with no alignment
// ============================================================================
void* malloc(unsigned int size) {
    EAHeap* heap = MainHeap();
    return heap->Malloc(size, 0);
}

// ============================================================================
// free - 0x802d12c0 (52 bytes)
// C free - frees through MainHeap
// ============================================================================
void free(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}

// ============================================================================
// realloc - 0x802d1348 (64 bytes)
// C realloc - calls GeneralAllocator::Realloc through MainHeap
// ============================================================================
// NON_MATCHING - register allocation for 3 args to Realloc
void* realloc(void* ptr, unsigned int size) {
    EAHeap* heap = MainHeap();
    return heap->Realloc(ptr, size, 0);
}

// ============================================================================
// __tcf_0 through __tcf_12 - Static destructor registration functions
// Each calls GeneralAllocator::~GeneralAllocator(mode=2) on a static heap
// These are atexit-registered cleanup functions for global heap objects
// All are 44 bytes each, same pattern
// ============================================================================
// __tcf_0 - 0x802cfe38 - destroys the RootHeap static object
// __tcf_1 - 0x802cfed4 - destroys the MainHeap static object
// __tcf_2 - 0x802cff74 - destroys the ResourceHeap static object
// __tcf_3 - 0x802d0014 - destroys the VMHeap static object
// __tcf_4 - 0x802d00b4 - destroys the DebugHeap static object
// __tcf_5 - 0x802d0150 - destroys the CUIHeap static object
// __tcf_6 - 0x802d01f0 - destroys the AudioHeap static object
// __tcf_7 - 0x802d02a0 - destroys the ShaderHeap static object
// __tcf_8 - 0x802d0350 - destroys the TextureHeap static object
// __tcf_9 - 0x802d0400 - destroys the AnimationHeap static object
// __tcf_10 - 0x802d04b0 - destroys the ModelHeap static object
// __tcf_11 - 0x802d0560 - destroys the FlashesHeap static object
// __tcf_12 - 0x802d0600 - destroys the AptHeap static object
// NON_MATCHING - These are compiler-generated static destructor registrations.
// They call ~GeneralAllocator(2) on the static heap objects.
// Cannot be reproduced from C++ source directly - they are generated
// by the compiler for static objects with destructors.
