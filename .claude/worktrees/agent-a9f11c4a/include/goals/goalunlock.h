#ifndef GOALUNLOCK_H
#define GOALUNLOCK_H

#include "types.h"

// Forward declarations
class ReconBuffer;

// ============================================================================
// IGoalUnlock - Interface for the goal/unlock system
// Object file: goalunlock.obj
// ============================================================================
class IGoalUnlock {
public:
    enum UnlockType {
        kUnlockType_Objects    = 0,  // 32 unlock slots
        kUnlockType_1          = 1,  // 208 unlock slots
        kUnlockType_2          = 2,  // 24 unlock slots
        kUnlockType_3          = 3,  // falls through to 0 -> 32 slots
        kUnlockType_4          = 4,  // falls through to 0 -> 32 slots
        kUnlockType_5          = 5,  // 128 unlock slots
    };

    virtual int GetObjectIndexFromGuid(int guid) = 0;
    virtual void ClearGoalsAndUnlocks() = 0;
    virtual int GetUnlockCount(UnlockType type) = 0;
    virtual int GetUnlockTotal(UnlockType type) = 0;
    virtual int IsUnlocked(UnlockType type, short index) = 0;
    virtual void GrantUnlock(UnlockType type, short index) = 0;
    virtual void GrantObjectUnlocks(int guid) = 0;
    virtual int IsRecentlyUnlocked(UnlockType type, short index) = 0;
    virtual void SetRecentlyUnlocked(UnlockType type, short index, bool recent) = 0;
    virtual void DoStream(ReconBuffer* buffer, int version) = 0;
    virtual ~IGoalUnlock();
};

// ============================================================================
// GoalUnlock - Concrete implementation of IGoalUnlock
// Object file: goalunlock.obj
//
// Memory layout:
//   +0x00: vtable pointer
//   +0x04: u8 m_unlockData[128]  (unlock flags / bitfields)
//
// Total size: 132 bytes (0x84)
// ============================================================================
class GoalUnlock : public IGoalUnlock {
public:
    u8 m_unlockData[128];  // +0x04

    GoalUnlock();
    virtual ~GoalUnlock();

    virtual int GetObjectIndexFromGuid(int guid);
    virtual void ClearGoalsAndUnlocks();
    virtual int GetUnlockCount(UnlockType type);
    virtual int GetUnlockTotal(UnlockType type);
    virtual int IsUnlocked(UnlockType type, short index);
    virtual void GrantUnlock(UnlockType type, short index);
    virtual void GrantObjectUnlocks(int guid);
    virtual int IsRecentlyUnlocked(UnlockType type, short index);
    virtual void SetRecentlyUnlocked(UnlockType type, short index, bool recent);
    virtual void DoStream(ReconBuffer* buffer, int version);

    void SetupObjectUnlockInfo();
    int GetFirstUnlockVar(UnlockType type);
};

#endif // GOALUNLOCK_H
