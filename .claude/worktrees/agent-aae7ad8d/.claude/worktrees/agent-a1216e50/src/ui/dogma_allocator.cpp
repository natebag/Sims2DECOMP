// DogmaAllocator.cpp - DOGMA pool-based memory allocator
// Source: libaptz.a(DogmaAllocator.cpp.obj)
// 8 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.
// The operator new/delete functions use gAptFuncs function pointer table
// via indirect calls (blrl), which GCC cannot replicate exactly.

#include "ui/dogma_allocator.h"

// ============================================================================
// gAptFuncs - global APT function table
// Located at 0x8049C060 in BSS
// Layout:
//   [0] = allocate function pointer (used by operator new/new[])
//   [1] = free function pointer (used by operator delete)
//   ... more entries
// Access pattern:
//   lis r9,0x804A / lwz r0,-0x3FA0(r9) => gAptFuncs[0] for alloc
//   lis r9,0x804A / lwz r0,-0x3F98(r9) => gAptFuncs[1] for free
// ============================================================================
typedef void* (*AptAllocFunc)(unsigned int);
typedef void (*AptFreeFunc)(void*, unsigned int);

extern AptAllocFunc gAptAllocFunc;  // gAptFuncs[0] at 0x8049C060
extern AptFreeFunc gAptFreeFunc;    // gAptFuncs[1] at 0x8049C068

// ============================================================================
// DOGMA_PoolManager::operator new (0x802b55ac, 44 bytes) NON_MATCHING
// Original:
//   stwu r1,-8(r1) / mflr r0 / stw r0,12(r1)
//   lis r9,0x804A / lwz r0,-0x3FA0(r9)  ; load gAptFuncs[0] (alloc func)
//   mtlr r0 / blrl                        ; call function pointer
//   epilogue
// Calls the global APT allocator function pointer with size.
// ============================================================================
void* DOGMA_PoolManager::operator new(unsigned int size) {
    return gAptAllocFunc(size);
}

// ============================================================================
// DOGMA_PoolManager::operator delete (0x802b55d8, 44 bytes) NON_MATCHING
// Original:
//   lis r9,0x804A / lwz r0,-0x3F98(r9)  ; load gAptFuncs[1] (free func)
//   mtlr r0 / blrl                        ; call function pointer
// Calls the global APT free function pointer with ptr and size.
// ============================================================================
void DOGMA_PoolManager::operator delete(void* ptr, unsigned int size) {
    gAptFreeFunc(ptr, size);
}

// ============================================================================
// DOGMA_PoolManager::operator new[] (0x802b5604, 44 bytes) NON_MATCHING
// Original: Same pattern as operator new - loads gAptFuncs[0] and calls it.
// ============================================================================
void* DOGMA_PoolManager::operator new[](unsigned int size) {
    return gAptAllocFunc(size);
}

// ============================================================================
// DOGMA_PoolManager::operator delete[] (0x802b5630, 44 bytes) NON_MATCHING
// Original: Same pattern as operator delete - loads gAptFuncs[1] and calls it.
// ============================================================================
void DOGMA_PoolManager::operator delete[](void* ptr, unsigned int size) {
    gAptFreeFunc(ptr, size);
}

// ============================================================================
// DOGMA_PoolManager::GetFirstOutsideAllocation (0x802b5818, 24 bytes) NON_MATCHING
// Original:
//   lwz r3,20(r3)         ; load m_outsideAllocList at offset 0x14
//   cmpwi r3,0            ; check if null
//   addi r3,r3,8          ; advance past header to data
//   bnelr                 ; return data pointer if non-null
//   li r3,0               ; return NULL if list empty
//   blr
// ============================================================================
void* DOGMA_PoolManager::GetFirstOutsideAllocation() {
    void* node = *(void**)((u8*)this + 0x14);
    if (node != 0) {
        return (u8*)node + 8;
    }
    return 0;
}

// ============================================================================
// DOGMA_PoolManager::GetNextOutsideAllocation (0x802b5830, 24 bytes) NON_MATCHING
// Original:
//   lwz r3,-8(r4)         ; load next pointer at current-8 (header.m_next)
//   cmpwi r3,0
//   addi r3,r3,8          ; advance past header
//   bnelr
//   li r3,0
//   blr
// The outside allocation has an 8-byte header: [next_ptr, ???, data...]
// So current-8 = header start, header[0] = next node pointer.
// ============================================================================
void* DOGMA_PoolManager::GetNextOutsideAllocation(void* current) {
    void* next = *(void**)((u8*)current - 8);
    if (next != 0) {
        return (u8*)next + 8;
    }
    return 0;
}

// ============================================================================
// DOGMA_PoolManager::ToNextValidSize (0x802b5b18, 44 bytes) NON_MATCHING
// Original:
//   andi. r0,r4,3         ; check if size is 4-byte aligned
//   beq aligned
//   clrrwi r4,r4,2        ; clear bottom 2 bits (round down)
//   addi r4,r4,4          ; add 4 (round up to next 4-byte boundary)
// aligned:
//   lwz r0,16(r3)         ; load m_poolFlags at offset 0x10
//   rlwinm r0,r0,28,28,31 ; extract bits 28-31 shifted right (min alloc size)
//   cmplw r4,r0           ; compare requested vs minimum
//   bge done
//   mr r4,r0              ; use minimum if larger
// done:
//   mr r3,r4              ; return size
//   blr
// ============================================================================
unsigned int DOGMA_PoolManager::ToNextValidSize(unsigned int size) {
    // Align to 4 bytes
    if (size & 3) {
        size = (size & ~3u) + 4;
    }
    // Enforce minimum allocation size from pool flags
    u32 flags = *(u32*)((u8*)this + 0x10);
    u32 minSize = (flags >> 4) & 0xF;  // Extract bits 4-7 after rotate
    if (size < minSize) {
        size = minSize;
    }
    return size;
}

// ============================================================================
// DOGMA_PoolManager::GetTotalBytesUsed (0x802b5b44, 40 bytes) NON_MATCHING
// Original:
//   lwz r11,4(r3)         ; load m_blockList at offset 0x04
//   li r3,0               ; total = 0
// loop:
//   lwz r0,4(r11)         ; block.m_end
//   lwz r9,8(r11)         ; block.m_start (free offset)
//   lwz r11,0(r11)        ; block.m_next
//   subf r0,r9,r0         ; used = end - start
//   add r3,r3,r0          ; total += used
//   cmpwi r11,0           ; more blocks?
//   bne loop
//   blr
// Iterates through block linked list summing (m_end - m_start) for each block.
// ============================================================================
unsigned int DOGMA_PoolManager::GetTotalBytesUsed() {
    struct Block {
        Block* m_next;
        u32 m_end;
        u32 m_start;
    };
    Block* block = *(Block**)((u8*)this + 0x04);
    unsigned int total = 0;
    while (block != 0) {
        total += block->m_end - block->m_start;
        block = block->m_next;
    }
    return total;
}
