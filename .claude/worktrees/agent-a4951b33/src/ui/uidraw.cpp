// uidraw.cpp - Small functions (<=64 bytes) from uidraw.obj
//
// Compiled with: powerpc-eabi-g++ -mcpu=750 -meabi -mhard-float -O2
//                -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar
//                -nostdinc++ -Iinclude -c

#include "ui/uidraw.h"

// ============================================================================
// External function declarations
// ============================================================================
extern "C" {
    void* __builtin_new(unsigned int size);
}

// ============================================================================
// UIDrawTable functions (from uidraw.obj)
// ============================================================================

// 0x8017aa1c - 52 bytes
// Walks the linked list checking if any record's functor thunk (at offset 0x0C)
// matches the thunk from the passed CBFunctor1 reference.
//
// NON_MATCHING: GCC hoists the functor dereference (lwz r8,0(r4)) before the
// loop, and the loop structure uses b+bne instead of original's bne+mr. pattern.
// Original: loads record thunk, loads next, compares, branches.
// GCC: loads functor thunk once, then loops comparing record thunks.
// Functionally identical but different instruction ordering.
int UIDrawTable::ContainsEntry(CBFunctor1<ERC*>& functor) {
    DrawTableRecord* record = m_head;
    if (record == 0) {
        return 0;
    }
    while (1) {
        if (record->m_functorThunk == *(int*)&functor) {
            return 1;
        }
        record = (DrawTableRecord*)record->m_next;
        if (record == 0) {
            return 0;
        }
    }
}

// 0x8017ab18 - 60 bytes
// NON_MATCHING: GCC uses absolute addressing for s_pInstance instead of
// r13-relative SDA addressing. Also generates early-return branch structure
// vs original's linear prologue-check-allocate-epilogue flow.
UIDrawTable* UIDrawTable::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new UIDrawTable();
    }
    return s_pInstance;
}
