// commander.cpp - Decompiled small functions from commander.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\commander.obj
//
// 4 small functions (<=64 bytes) decompiled

#include "objects/commander.h"

// Static members
// Commander::sList at 0x804FDBD4 (SDA r13-32076)
// Commander::sId at 0x804FDBD8 (SDA r13-32072)

// Commander vtable at 0x8045EBE8

// ============================================================================
// Commander::Commander
// Address: 0x800B4214, Size: 60 bytes
// NON_MATCHING - register allocation and SDA access pattern
// Inserts this commander into the linked list and assigns an ID
// ============================================================================
Commander::Commander() {
    // Set vtable (lis r9, 0x8046 / addi r9, -5144 = 0x8045EBE8)
    // m_prev = sList (head of linked list)
    m_prev = sList;
    m_type = 0;
    // m_id = sId++
    m_id = sId;
    sList = this;
    sId = sId + 1;
}

// ============================================================================
// Commander::DoCommand
// Address: 0x800B42B4, Size: 8 bytes
// MATCHING
// Default virtual: always returns false (0)
// ============================================================================
bool Commander::DoCommand(short cmd, int param) {
    return false;
}

// ============================================================================
// Commander::GetType
// Address: 0x800B43DC, Size: 8 bytes
// MATCHING
// Returns the commander type
// ============================================================================
int Commander::GetType() {
    return m_type;
}

// ============================================================================
// Commander::GetNext
// Address: 0x800B43E4, Size: 8 bytes
// MATCHING
// Returns previous/next commander in linked list
// ============================================================================
Commander* Commander::GetNext() {
    return m_prev;
}
