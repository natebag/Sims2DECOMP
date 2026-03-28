// appmain.cpp - ESimsApp, STL containers, and TArray specializations
// From: appmain.obj
// Medium functions (65-128 bytes) decompiled from this object
//
// Functions decompiled:
//   _Base_bitset<3>::_M_do_find_first             @ 0x8039BE88 (104 bytes)
//   _Deque_base<SMS*>::_M_create_nodes            @ 0x8039BEF0 (76 bytes)
//   _Deque_base<SMS*>::_M_destroy_nodes           @ 0x8039C040 (84 bytes)
//   _Deque_base<SMS*>::~_Deque_base               @ 0x8039C094 (128 bytes)
//   __node_alloc<false,0>::_M_allocate             @ 0x8039C304 (80 bytes)
//   TArray<EVec3>::Deallocate                     @ 0x8039C664 (76 bytes)
//   TArray<ENLatticePoints>::Destruct             @ 0x8039C6F0 (80 bytes)
//   TArray<ENLatticePoints>::Construct            @ 0x8039C784 (76 bytes)
//   TArray<EVec3>::operator=                      @ 0x8039C94C (76 bytes)
//   TArray<ENLatticePoints>::Copy                 @ 0x8039C998 (88 bytes)

#include "core/appmain.h"
#include "core/statemachine.h"
#include "core/eaheap.h"

// Placement new (no <new> header in decomp)
inline void* operator new(unsigned int, void* p) { return p; }

// ============================================================================
// External references
// ============================================================================

// Lookup tables (in .data section)
// _Bs_G<bool>::_S_first_one at 0x8045a9f0 (256 bytes)
// __node_alloc<false,0>::_S_free_list at 0x8045a8b0 (32 bytes = 8 pointers)

// Heap functions
extern "C" {
    EAHeap* MainHeap(void);                    // 0x802cff00
}

// ============================================================================
// __node_alloc<false, 0>::_M_allocate
// Address: 0x8039C304, Size: 0x50 (80 bytes)
// Allocates memory from the free list. If free list for this size class is
// empty, calls _S_refill to get more.
//
// Disassembly:
//   r10 = __n (size)
//   r0 = __n - 1
//   r11 = (r0 >> 1) & ~3 (rlwinm r11,r0,31,1,29) -> byte offset into free list
//   lwzx r3, r11, r9 where r9 = _S_free_list base
//   if r3 != 0: take from free list, return
//   else: call _S_refill(__n)
// ============================================================================
void* __node_alloc_false_0_M_allocate(unsigned int __n);

// ============================================================================
// _Base_bitset<3>::_M_do_find_first
// Address: 0x8039BE88, Size: 0x68 (104 bytes)
// Finds the first set bit in the bitset. Returns __not_found if none set.
// Iterates through 3 words, checking each byte via _S_first_one lookup table.
// ============================================================================
// NON_MATCHING - the original uses CTR loop for inner byte scan and specific
// register allocation that's difficult to match with C++ template specialization.
// Implemented as free function to avoid template instantiation ordering issues.
unsigned int Base_bitset_3_M_do_find_first(const unsigned int* _M_w, unsigned int __not_found) {
    unsigned int __i = 0;
    unsigned int __bitoffset = 0;
    extern unsigned char _Bs_G_S_first_one[256]; // 0x8045a9f0
    while (__i <= 2) {
        unsigned int __thisword = _M_w[__i];
        if (__thisword != 0) {
            unsigned int __pos = __bitoffset;
            for (int __j = 0; __j < 4; __j++) {
                unsigned char __byte = (unsigned char)__thisword;
                if (__byte != 0) {
                    return __pos + _Bs_G_S_first_one[__byte];
                }
                __thisword >>= 8;
                __pos += 8;
            }
        }
        __i++;
        __bitoffset += 32;
    }
    return __not_found;
}

// ============================================================================
// _Deque_base<StateMachineStatus*, allocator<StateMachineStatus*>>::_M_create_nodes
// Address: 0x8039BEF0, Size: 0x4C (76 bytes)
// Allocates 128-byte buffer nodes for each map slot in [__nstart, __nfinish).
// ============================================================================
// NON_MATCHING - template specialization ordering
void Deque_base_SMS_M_create_nodes(
    StateMachineStatus*** __nstart, StateMachineStatus*** __nfinish)
{
    StateMachineStatus*** __cur = __nstart;
    while (__cur < __nfinish) {
        *__cur = (StateMachineStatus**)__node_alloc_false_0_M_allocate(128);
        __cur++;
    }
}

// ============================================================================
// _Deque_base<StateMachineStatus*, allocator<StateMachineStatus*>>::_M_destroy_nodes
// Address: 0x8039C040, Size: 0x54 (84 bytes)
// Deallocates buffer nodes for each map slot in [__nstart, __nfinish).
// ============================================================================
// NON_MATCHING - template specialization ordering
extern void __node_alloc_false_0_M_deallocate(void* __p, unsigned int __n);
void Deque_base_SMS_M_destroy_nodes(
    StateMachineStatus*** __nstart, StateMachineStatus*** __nfinish)
{
    StateMachineStatus*** __cur = __nstart;
    while (__cur < __nfinish) {
        StateMachineStatus** __node = *__cur;
        if (__node != 0) {
            __node_alloc_false_0_M_deallocate(__node, 128);
        }
        __cur++;
    }
}

// ============================================================================
// _Deque_base<StateMachineStatus*, allocator<StateMachineStatus*>>::~_Deque_base
// Address: 0x8039C094, Size: 0x80 (128 bytes)
// Destructor: destroys nodes, frees map allocation.
// r4 = __in_chrg (destructor variant flag)
//
// Disassembly analysis:
//   lwz r0, 0x24(this)         -> m_mapAlloc (field at 0x24)
//   cmpwi r0, 0                -> if map allocated
//   lwz r5, 0x1C(this)         -> _M_finish._M_node (field at 0x1C)
//   lwz r4, 0x0C(this)         -> _M_start._M_node (field at 0x0C)
//   addi r5, r5, 4             -> __nfinish = _M_finish._M_node + 1
//   bl _M_destroy_nodes
//   lwz r3, 0x24(this)         -> map ptr
//   lwz r4, 0x2C(this)         -> map size alloc (field at 0x2C)
//   slwi r4, r4, 2             -> byte size = count * 4
//   cmplwi r4, 128
//   ble -> _M_deallocate       -> small alloc uses node_alloc
//   bl -> __builtin_delete      -> large alloc uses operator delete
// ============================================================================
// NON_MATCHING - complex destructor with conditional dealloc paths
// The destructor has two deallocation paths based on map size vs 128 bytes,
// which is hard to reproduce exactly in C++ without matching the STL internals.

// ============================================================================
// __node_alloc<false, 0>::_M_allocate (actual implementation)
// Address: 0x8039C304, Size: 0x50 (80 bytes)
// ============================================================================
void* __node_alloc_false_0_M_allocate(unsigned int __n) {
    extern void* __node_alloc_false_0_S_free_list[8]; // 0x8045a8b0
    extern void* __node_alloc_false_0_S_refill(unsigned int __n);
    // rlwinm r11,r0,31,1,29: shifts right by 1, masks bits 1-29
    // This is equivalent to ((__n - 1) >> 1) & 0x7FFFFFFC
    // = ((__n-1) & ~7) >> 1 -- a byte offset, then lwzx uses it
    // Effectively: free_list_index = (__n - 1) / 8
    unsigned int __byte_offset = ((__n - 1) >> 1) & 0x7FFFFFFC;
    void** __my_free_list = (void**)((char*)__node_alloc_false_0_S_free_list + __byte_offset);
    void* __result = *__my_free_list;
    if (__result != 0) {
        *__my_free_list = *(void**)__result;
        return __result;
    }
    return __node_alloc_false_0_S_refill(__n);
}

// ============================================================================
// TArray<EVec3, TArrayDefaultAllocator>::Deallocate
// Address: 0x8039C664, Size: 0x4C (76 bytes)
// Deallocates the array's buffer via MainHeap()->Free()
//
// Disassembly:
//   calls Destruct(m_data, m_size)    -> 0x8039c634
//   r29 = m_data                      -> saves pointer
//   calls MainHeap()                  -> 0x802cff00
//   calls EAHeap::Free(r29)           -> 0x802d0d78
//   calls Init()                      -> 0x8039c650
// ============================================================================
void TArray<EVec3, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_size);
    void* ptr = m_data;
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
    Init();
}

// ============================================================================
// TArray<ENLatticePoints, TArrayDefaultAllocator>::Destruct
// Address: 0x8039C6F0, Size: 0x50 (80 bytes)
// Destructs count elements by calling ~TArray<EVec3> on each 12-byte element.
// Each ENLatticePoints contains a TArray<EVec3> that needs destruction.
//
// Disassembly:
//   loop count-1 down to 0:
//     mr r3, r30 (element ptr)
//     li r4, 2 (__in_chrg = 2 means delete after destruct)
//     bl TArray<EVec3>::~TArray  (0x8039c6b0)
//     addi r30, r30, 12
// ============================================================================
// NON_MATCHING - ENLatticePoints destruction calls ~TArray<EVec3> with stride 12,
// suggesting ENLatticePoints IS a TArray<EVec3>. This is a template instantiation
// quirk where the destructor iterates elements calling sub-destructors.
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Destruct(
    ENLatticePoints* ptr, int count)
{
    for (int i = count - 1; i >= 0; i--) {
        // Each ENLatticePoints element calls TArray<EVec3>::~TArray
        TArray<EVec3, TArrayDefaultAllocator>* arr =
            (TArray<EVec3, TArrayDefaultAllocator>*)ptr;
        arr->~TArray();
        ptr = (ENLatticePoints*)((u8*)ptr + 12);
    }
}

// ============================================================================
// TArray<ENLatticePoints, TArrayDefaultAllocator>::Construct
// Address: 0x8039C784, Size: 0x4C (76 bytes)
// Constructs count elements by calling TArray<EVec3>::TArray() on each.
//
// Disassembly:
//   loop count-1 down to 0:
//     mr r3, r30 (element ptr)
//     bl TArray<EVec3>::TArray(void)  (0x8039c754)
//     addi r30, r30, 12
// ============================================================================
// NON_MATCHING - ENLatticePoints construction calls TArray<EVec3>::TArray()
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Construct(
    ENLatticePoints* dst, int count)
{
    for (int i = count - 1; i >= 0; i--) {
        TArray<EVec3, TArrayDefaultAllocator>* arr =
            (TArray<EVec3, TArrayDefaultAllocator>*)dst;
        new (arr) TArray<EVec3, TArrayDefaultAllocator>();
        dst = (ENLatticePoints*)((u8*)dst + 12);
    }
}

// ============================================================================
// TArray<EVec3, TArrayDefaultAllocator>::operator=
// Address: 0x8039C94C, Size: 0x4C (76 bytes)
// Assignment operator: resizes to match source, then copies data.
//
// Disassembly:
//   lwz r4, 4(other)           -> other.m_size
//   li r5, 0                   -> growBy = 0
//   bl SetSize(other.m_size, 0)
//   lwz r3, 0(this)            -> this->m_data
//   lwz r5, 4(other)           -> other.m_size
//   lwz r4, 0(other)           -> other.m_data
//   bl Copy(this->m_data, other.m_data, other.m_size)
//   return this
// ============================================================================
TArray<EVec3, TArrayDefaultAllocator>&
TArray<EVec3, TArrayDefaultAllocator>::operator=(
    TArray<EVec3, TArrayDefaultAllocator>& other)
{
    SetSize(other.m_size, 0);
    Copy(m_data, other.m_data, other.m_size);
    return *this;
}

// ============================================================================
// TArray<ENLatticePoints, TArrayDefaultAllocator>::Copy
// Address: 0x8039C998, Size: 0x58 (88 bytes)
// Copies count elements from src to dst using per-element operator= on the
// underlying TArray<EVec3>.
//
// Disassembly:
//   loop count-1 down to 0:
//     mr r3, r29 (dst element)
//     mr r4, r30 (src element)
//     bl TArray<EVec3>::operator=  (0x8039c94c)
//     addi r30, r30, 12
//     addi r29, r29, 12
// ============================================================================
// NON_MATCHING - Per-element copy via TArray<EVec3>::operator=
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Copy(
    ENLatticePoints* dst, ENLatticePoints* src, int count)
{
    for (int i = count - 1; i >= 0; i--) {
        TArray<EVec3, TArrayDefaultAllocator>* d =
            (TArray<EVec3, TArrayDefaultAllocator>*)dst;
        TArray<EVec3, TArrayDefaultAllocator>* s =
            (TArray<EVec3, TArrayDefaultAllocator>*)src;
        *d = *s;
        src = (ENLatticePoints*)((u8*)src + 12);
        dst = (ENLatticePoints*)((u8*)dst + 12);
    }
}
