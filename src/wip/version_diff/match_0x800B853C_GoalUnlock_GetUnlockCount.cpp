// GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType)
// 96 bytes, switch statement returning constants

class IGoalUnlock {
public:
    enum UnlockType { Type0, Type1, Type2, Type3, Type4, Type5 };
};

class GoalUnlock {
public:
    int GetUnlockCount(IGoalUnlock::UnlockType type);
};

int GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType type) {
    switch (type) {
        case IGoalUnlock::Type2: return 32;
        case IGoalUnlock::Type0: return 208;
        case IGoalUnlock::Type1: return 24;
        case IGoalUnlock::Type4: return 128;
        case IGoalUnlock::Type5: return 0;
        default: return 0;
    }
}
