#ifndef GOALUNLOCK_H
#define GOALUNLOCK_H

#include "types.h"

// GoalUnlock - struct layout extracted from assembly analysis
// Estimated minimum size: 0xE (14 bytes)
// 3 known fields (3 named), 28 methods

class GoalUnlock {
public:
    // Static members (from map file)
    // static ??? kNumGoalAndUnlockVariables;

    // Constructors / Destructors
    GoalUnlock(void)  // 0x8023CDB4
    ~GoalUnlock(void);  // 0x8023CE08

    // Methods
    void SetupObjectUnlockInfo(void);  // 0x8023D070 (656B)
    void ClearGoalsAndUnlocks(void);  // 0x8023CF04 (68B)
    void DoStream(ReconBuffer *, int);  // 0x8023CE64 (160B)
    /* ? */ GetUnlockCount(IGoalUnlock::UnlockType);  // 0x8023CF48 (296B)
    /* ? */ GetObjectIndexFromGuid(int);  // 0x8023D300 (224B)
    /* ? */ GetFirstUnlockVar(IGoalUnlock::UnlockType);  // 0x8023D3E0 (320B)
    bool IsUnlocked(IGoalUnlock::UnlockType, short);  // 0x8023D520 (556B)
    void GrantUnlock(IGoalUnlock::UnlockType, short);  // 0x8023D74C (604B)
    void GrantObjectUnlocks(int);  // 0x8023D9A8 (536B)
    bool IsRecentlyUnlocked(IGoalUnlock::UnlockType, short);  // 0x8023DBC0 (564B)
    void SetRecentlyUnlocked(IGoalUnlock::UnlockType, short, bool);  // 0x8023DDF4 (624B)
    /* ? */ GetUnlockTotal(IGoalUnlock::UnlockType);  // 0x8023E064 (256B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_unlockTotal;  // 0x000 [R] (DoStream, GetObjectIndexFromGuid, GetUnlockTotal, ...)
    u32 m_upObjectUnlockInfo;  // 0x004 [R] (SetupObjectUnlockInfo)
    u8 _pad_008[4];  // 0x008
    u16 m_upObjectUnlockInfo_00C;  // 0x00C [R] (SetupObjectUnlockInfo)
};

#endif // GOALUNLOCK_H
