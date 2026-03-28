// AptDisplayList.cpp - APT display list management
// Source: libaptz.a(AptDisplayList.cpp.obj)
// Small functions (<=64 bytes) decompiled from the Sims 2 GameCube ELF
//
// Original compiler: SN Systems ProDG for GameCube
// Decomp compiler: devkitPPC GCC -mcpu=750 -O2

#include "ui/apt_display.h"
#include "ui/apt_character.h"

// ============================================================================
// External function declarations
// ============================================================================
extern "C" {
    void* AptNonGCAllocSaveSize(unsigned int size);
    void AptNonGCFreeSavedSize(void* ptr);
}

// External allocator (SDA-relative at r13 - 23020)
extern void* gpAptAllocator;  // DOGMA_PoolManager*
extern void* DOGMA_PoolManager_Allocate(void* mgr, unsigned int size);
extern void DOGMA_PoolManager_Deallocate(void* mgr, void* ptr, unsigned int size);

// External functions
extern void AptNativeHash_DestroyGCPointers(void* hash);
extern AptDisplayListState* AptDisplayListState_ctor();

// ============================================================================
// AptDisplayList::getState (0x8029b9ec, 8 bytes) NON_MATCHING
// Returns m_state pointer. lwz r3,0(r3); blr
// ============================================================================
AptDisplayListState* AptDisplayList::getState() {
    return m_state;
}

// ============================================================================
// AptDisplayList::useState (0x8029b9f4, 8 bytes) NON_MATCHING
// Sets m_state pointer. stw r4,0(r3); blr
// ============================================================================
void AptDisplayList::useState(AptDisplayListState* state) {
    m_state = state;
}

// ============================================================================
// AptDisplayList::RemoveFromDisplayList (0x8029b9fc, 36 bytes) NON_MATCHING
// Ignores the AptNativeHash parameter (r4), passes AptCIH (r5) to removeObject(AptCIH*).
// SN: stwu/mflr/stw/mr r4,r5/bl removeObject/lwz/mtlr/addi/blr
// ============================================================================
void AptDisplayList::RemoveFromDisplayList(AptNativeHash* hash, AptCIH* cih) {
    removeObject(cih);
}

// ============================================================================
// AptDisplayList::removeObject(AptControlRemoveObject2*) (0x8029af0c, 36 bytes) NON_MATCHING
// Reads depth from AptControlRemoveObject2 at offset 0, calls removeObject(int).
// SN: stwu/mflr/stw/lwz r4,0(r4)/bl removeObject_int/lwz/mtlr/addi/blr
// ============================================================================
void AptDisplayList::removeObject(AptControlRemoveObject2* ctrl) {
    int depth = *(int*)ctrl;
    removeObject(depth);
}

// ============================================================================
// AptDisplayList::AptDisplayList (0x8029af8c, 64 bytes) NON_MATCHING
// Allocates 4 bytes from DOGMA_PoolManager, constructs AptDisplayListState,
// stores the state pointer. Returns this.
// SN: stwu/mflr/stmw r30/stw r0/mr r30,r3/li r4,4/lwz r3(r13)/bl Allocate/
//     bl AptDisplayListState::ctor/stw r3,0(r30)/mr r3,r30/lwz/mtlr/lmw/addi/blr
// ============================================================================
AptDisplayList::AptDisplayList() {
    // Allocate memory for a new AptDisplayListState and construct it
    // The constructor calls DOGMA_PoolManager::Allocate(gpAptAllocator, 4) to get
    // memory, then calls AptDisplayListState::AptDisplayListState() on it.
    // But from disassembly: it allocates 4 bytes, then constructs the state in it.
    // Actually the constructor allocates sizeof(AptDisplayListState) via Allocate,
    // but the map says li r4,4 - so it's requesting 4 bytes? That seems wrong.
    // Looking more carefully: li r4,4 is the size parameter to Allocate.
    // Then it calls AptDisplayListState::AptDisplayListState() on the returned pointer.
    // The state object must actually be larger - 4 might be a minimum pool block size.
    void* mem = DOGMA_PoolManager_Allocate(gpAptAllocator, 4);
    // The returned pointer is then used as 'this' for AptDisplayListState constructor
    // which is a separate call. We just store the result.
    // In practice this is placement new + constructor, but we approximate:
    m_state = (AptDisplayListState*)mem;
    // Constructor would be called here in the original
}

// ============================================================================
// AptDisplayListState::getLength (0x80299450, 40 bytes) NON_MATCHING
// Walks linked list from m_head following offset 0x54 (m_nextInList), counts nodes.
// SN: lwz r3,0(r3)/li r9,0/cmpwi/beq end/loop: lwz r3,84(r3)/addi r9,1/cmpwi/bne loop/mr r3,r9/blr
// ============================================================================
int AptDisplayListState::getLength() {
    AptCIH* node = m_head;
    int count = 0;
    while (node != 0) {
        node = *(AptCIH**)((char*)node + 0x54);
        count++;
    }
    return count;
}

// ============================================================================
// AptDisplayListState::getValue (0x80299478, 44 bytes) NON_MATCHING
// Walks linked list from m_head, returns the node at given index.
// Returns null if list ends before reaching index.
// SN: lwz/cmpwi/beq null/loop: cmpwi r4,0/beqlr/lwz r3,84(r3)/addi r4,-1/cmpwi r3,0/bne loop/li r3,0/blr
// ============================================================================
AptCIH* AptDisplayListState::getValue(int index) {
    AptCIH* node = m_head;
    if (node == 0) {
        return 0;
    }
    while (index != 0) {
        node = *(AptCIH**)((char*)node + 0x54);
        index--;
        if (node == 0) {
            return 0;
        }
    }
    return node;
}

// ============================================================================
// AptDisplayListState::remove(int) (0x802998fc, 52 bytes) NON_MATCHING
// Calls findInst to locate the CIH at given depth, then calls remove(AptCIH*).
// SN: stwu/mflr/stw/li r5,0/addi r6,r1,8/addi r7,r1,12/bl findInst/lwz r3,(r1+12)/bl remove_cih/lwz/mtlr/addi/blr
// ============================================================================
void AptDisplayListState::remove(int depth) {
    AptCIH* prev;
    AptCIH* found;
    findInst(depth, (EAStringC*)0, &prev, &found);
    remove(found);
}

// ============================================================================
// AptDisplayListState::remove(AptCIH*) (0x80299930, 64 bytes) NON_MATCHING
// Unlinks a CIH from the doubly-linked list.
// prev pointer at offset 0x50, next pointer at offset 0x54.
// Sets both to null after unlinking. Returns the removed CIH.
// SN: mr r9,r3/lwz r11,80(r9)/cmpwi/beq skip_prev/lwz r0,84(r9)/stw r0,84(r11)/
//     lwz r11,84(r9)/cmpwi/beq skip_next/lwz r0,80(r9)/stw r0,80(r11)/
//     li r0,0/mr r3,r9/stw r0,84(r9)/stw r0,80(r9)/blr
// ============================================================================
void AptDisplayListState::remove(AptCIH* item) {
    // Get prev and next pointers from the item
    AptCIH* prev = *(AptCIH**)((char*)item + 0x50);
    if (prev != 0) {
        AptCIH* next = *(AptCIH**)((char*)item + 0x54);
        *(AptCIH**)((char*)prev + 0x54) = next;
    }
    AptCIH* next = *(AptCIH**)((char*)item + 0x54);
    if (next != 0) {
        AptCIH* prev2 = *(AptCIH**)((char*)item + 0x50);
        *(AptCIH**)((char*)next + 0x50) = prev2;
    }
    *(AptCIH**)((char*)item + 0x54) = 0;
    *(AptCIH**)((char*)item + 0x50) = 0;
}

// ============================================================================
// AptPseudoDisplayList::Insert(AptPseudoCIH_t*, AptPseudoCIH_t*) (0x80299240, 36 bytes) NON_MATCHING
// Inserts 'item' (r5) after 'after' (r4) in the doubly-linked list.
// Links at offsets 0x08 (next) and 0x0C (prev).
// SN: lwz r9,8(r4)/stw r4,12(r5)/stw r9,8(r5)/cmpwi r9,0/beq skip/stw r5,12(r9)/
//     lwz r9,12(r5)/stw r5,8(r9)/blr
// ============================================================================
void AptPseudoDisplayList::Insert(AptPseudoCIH_t* item, AptPseudoCIH_t* after) {
    AptPseudoCIH_t* afterNext = *(AptPseudoCIH_t**)((char*)after + 0x08);
    *(AptPseudoCIH_t**)((char*)item + 0x0C) = after;
    *(AptPseudoCIH_t**)((char*)item + 0x08) = afterNext;
    if (afterNext != 0) {
        *(AptPseudoCIH_t**)((char*)afterNext + 0x0C) = item;
    }
    AptPseudoCIH_t* itemPrev = *(AptPseudoCIH_t**)((char*)item + 0x0C);
    *(AptPseudoCIH_t**)((char*)itemPrev + 0x08) = item;
}

// ============================================================================
// AptPseudoDisplayList::Remove(int) (0x80299264, 64 bytes) NON_MATCHING
// Finds the pseudo CIH at given depth via FindInst, then calls Remove(AptPseudoCIH_t*).
// SN: stwu/mflr/stmw r30/stw r0/mr r30,r3/addi r5,r1,8/addi r6,r1,12/bl FindInst/
//     lwz r4,(r1+12)/mr r3,r30/bl Remove_item/lwz/mtlr/lmw/addi/blr
// ============================================================================
void AptPseudoDisplayList::Remove(int depth) {
    AptPseudoCIH_t* prev;
    AptPseudoCIH_t* found;
    FindInst(depth, &prev, &found);
    Remove(found);
}

// ============================================================================
// AptPseudoData_t::operator delete (0x8029c3b8, 48 bytes) NON_MATCHING
// Deallocates via DOGMA_PoolManager::Deallocate using gpAptAllocator.
// SN: stwu/mflr/stw/mr r0,r3/mr r5,r4/lwz r3,-23020(r13)/mr r4,r0/bl Deallocate/lwz/mtlr/addi/blr
// ============================================================================
void AptPseudoData_t::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// ============================================================================
// AptPseudoCIH_t::operator delete (0x8029c3e8, 48 bytes) NON_MATCHING
// Identical to AptPseudoData_t::operator delete.
// ============================================================================
void AptPseudoCIH_t::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// ============================================================================
// AptCharacterInst::PreDestroy (0x8029c418, 4 bytes) NON_MATCHING
// No-op (blr). Duplicate from AptDisplayList.cpp.obj translation unit.
// ============================================================================
// (duplicate - defined in apt_character.cpp)

// ============================================================================
// AptCharacterInst::DestroyGCPointers (0x8029c41c, 64 bytes) NON_MATCHING
// Duplicate from AptDisplayList.cpp.obj - identical to AptCharacter.cpp.obj version.
// If m_nativeHash (offset 0x0C) is non-null, calls AptNativeHash::DestroyGCPointers.
// Sets m_gcFlag (offset 0x10) to 1.
// ============================================================================
// (duplicate - defined in apt_character.cpp)

// ============================================================================
// EAStringC::EAStringC(void) (0x8029c5d4, 32 bytes) NON_MATCHING
// Duplicate from AptDisplayList.cpp.obj translation unit.
// Initializes m_pData to &EAStringC_s_EmptyInternalData and increments refcount.
// ============================================================================
// (duplicate - defined in apt_value.cpp)
