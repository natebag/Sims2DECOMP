// goalunlock.cpp - GoalUnlock system
// Object file: goalunlock.obj
// 3 small functions (<=64 bytes) decompiled from Sims 2 GC
//
// All functions are NON_MATCHING due to GCC vs SN Systems compiler differences:
//   - GCC uses D0/D1 destructor split; SN uses single destructor with delete flag
//   - GCC tail-call optimizes memset/ClearGoalsAndUnlocks; SN uses stack frame + bl
//   - GCC uses stw/lwz; SN uses stmw/lmw for register save/restore
//
// GoalUnlock layout (132 bytes):
//   +0x00: vtable pointer (4 bytes)
//   +0x04: u8 m_unlockData[128] (unlock flags / bitfields)
//
// GoalUnlock vtable @ 0x8045f040 (SN 8-byte entries: [adjustor, function_ptr]):
//   vfunc[0]: GetObjectIndexFromGuid(int) @ 0x800b86d8
//   vfunc[1]: ClearGoalsAndUnlocks() @ 0x800b8510
//   vfunc[2]: GetUnlockCount(UnlockType) @ 0x800b853c
//   vfunc[3]: GetUnlockTotal(UnlockType) @ 0x800b8bf4
//   vfunc[4]: IsUnlocked(UnlockType, short) @ 0x800b87cc
//   vfunc[5]: GrantUnlock(UnlockType, short) @ 0x800b8880
//   vfunc[6]: GrantObjectUnlocks(int) @ 0x800b894c
//   vfunc[7]: IsRecentlyUnlocked(UnlockType, short) @ 0x800b8a6c
//   vfunc[8]: SetRecentlyUnlocked(UnlockType, short, bool) @ 0x800b8b24
//   vfunc[9]: DoStream(ReconBuffer*, int) @ 0x800b84a8
//   vfunc[10]: ~GoalUnlock() @ 0x800b8474
//
// s_objectUnlocks @ 0x80485e7c (0x400 = 1024 bytes, .data section)

#include "goals/goalunlock.h"

// External runtime functions
extern "C" void* memset(void* s, int c, unsigned int n);

// ============================================================================
// IGoalUnlock base class
// ============================================================================

// IGoalUnlock virtual destructor (base class, minimal)
IGoalUnlock::~IGoalUnlock() {
}

// ============================================================================
// GoalUnlock
// ============================================================================

// NON_MATCHING: GCC inlines ClearGoalsAndUnlocks into tail-call to memset;
// SN creates stack frame, stores r30 (this) with stmw, calls ClearGoalsAndUnlocks with bl
// GoalUnlock::GoalUnlock(void) @ 0x800b8438, 60 bytes
// Original:
//   stwu r1,-16(r1); mflr r0; stmw r30,8(r1); stw r0,20(r1)
//   lis r9,0x8046; mr r30,r3; addi r9,r9,0xf040 (vtable addr)
//   stw r9,0(r30)    ; set vtable
//   bl ClearGoalsAndUnlocks
//   mr r3,r30        ; return this
//   <restore and return>
GoalUnlock::GoalUnlock() {
    ClearGoalsAndUnlocks();
}

// NON_MATCHING: GCC D0/D1 split vs SN single destructor with delete flag in r4
// GoalUnlock::~GoalUnlock(void) @ 0x800b8474, 52 bytes
// Original:
//   stwu r1,-8(r1); mflr r0; stw r0,12(r1)
//   lis r9,0x8046; andi. r0,r4,1; addi r9,r9,0xf040
//   stw r9,0(r3)     ; reset vtable
//   beq skip_delete
//   bl __builtin_delete
//   skip_delete: <restore and return>
GoalUnlock::~GoalUnlock() {
}

// NON_MATCHING: GCC tail-calls memset (b memset); SN uses stack frame + bl memset + restore
// GoalUnlock::ClearGoalsAndUnlocks(void) @ 0x800b8510, 44 bytes
// Original:
//   stwu r1,-8(r1); mflr r0; stw r0,12(r1)
//   addi r3,r3,4     ; point past vtable to m_unlockData
//   li r4,0           ; fill value
//   li r5,128         ; 0x80 bytes
//   bl memset
//   <restore and return>
void GoalUnlock::ClearGoalsAndUnlocks() {
    memset(m_unlockData, 0, 128);
}
