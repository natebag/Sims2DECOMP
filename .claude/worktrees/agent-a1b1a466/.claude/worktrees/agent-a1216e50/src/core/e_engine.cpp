// e_engine.cpp - EEngine additional functions and e_frag.obj EFrameAllocGroup
// From: engine_ngc_release_dvd.lib(e_engine.obj, e_frag.obj)
// NOTE: Most EEngine small functions are in e_app.cpp alongside EApp.
// This file contains EFrameAllocGroup from e_frag.obj.

#include "core/e_app.h"

// ============================================================================
// External references
// ============================================================================

extern "C" {
    extern int _heapInitialized;  // r13 - 0x68FC = r13-26876 (from e_frag.obj context)
    void EAHeap_SystemInit(void);
    void _RingReset(void* ring);
    void _RingInit(void* ring, unsigned int size);
    void* _RingAlloc(void* ring, unsigned int size);
    void EStorable_BaseCtor(void* obj, int numSlots);
    void EStorable_ManagedShutdownBase(void* obj);
}

extern "C" void* EFrameAllocGroup_vtable_base[];  // 0x8046a120
extern "C" void* EFrameAllocGroup_vtable[];        // 0x8046aee8

// ============================================================================
// e_frag.obj - EFrameAllocGroup small functions (5 code + 2 data)
// ============================================================================

// EFrameAllocGroup::ManagedShutdown - 0x803066a8 (56 bytes)
// Resets both ring allocators
void EFrameAllocGroup::ManagedShutdown(void) {
    _RingReset((char*)this + 0x04);
    _RingReset((char*)this + 0x1C);
}

// EFrameAllocGroup::Update - 0x803066e0 (60 bytes)
// Toggles current ring and resets it
void EFrameAllocGroup::Update(void) {
    int* pCurrent = (int*)((char*)this + 0x34);
    int cur = *pCurrent;
    // Toggle: if cur != 0 then 0, else 1
    int next = cur ? 0 : 1;
    // Compute ring offset: next * 24 + 4
    int offset = next * 24 + 4;
    *pCurrent = next;
    _RingReset((char*)this + offset);
}

// EFrameAllocGroup::Alloc - 0x8030683c (48 bytes)
// Allocates from current ring
void* EFrameAllocGroup::Alloc(unsigned int size, int align) {
    int cur = *(int*)((char*)this + 0x34);
    int offset = cur * 24 + 4;
    return _RingAlloc((char*)this + offset, size);
}
