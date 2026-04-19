// 0x800B853C (96B) GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType)
// Switch on type, returns per-bucket count. Default 0.

class GoalUnlock_GUC {
public:
    int GetUnlockCount(int type);
};

int GoalUnlock_GUC::GetUnlockCount(int type) {
    switch (type) {
        case 0: return 32;
        case 1: return 208;
        case 2: return 24;
        case 3: return 32;
        case 4: return 32;
        case 5: return 128;
    }
    return 0;
}
