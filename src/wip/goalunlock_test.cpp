// 0x800B853C GoalUnlock::GetUnlockCount (96b)
// FLAGS: -fno-schedule-insns

class IGoalUnlock {
public:
    enum UnlockType { Type0, Type1, Type2, Type3, Type4, Type5 };
};

class GoalUnlock {
public:
    int GetUnlockCount(IGoalUnlock::UnlockType type);
};

int GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType type) {
    // Match DOL branch structure exactly
    if (type == IGoalUnlock::Type2) return 32;
    if (type > IGoalUnlock::Type2) {
        if (type == IGoalUnlock::Type4) return 128;
        if (type < IGoalUnlock::Type4) return 0; // Type3
        if (type == IGoalUnlock::Type5) return 0;
        return 0; // default
    }
    if (type == IGoalUnlock::Type0) return 208;
    if (type == IGoalUnlock::Type1) return 24;
    return 0;
}
