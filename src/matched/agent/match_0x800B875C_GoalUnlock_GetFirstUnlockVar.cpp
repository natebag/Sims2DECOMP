// 0x800B875C (112B) GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType)
// Switch 0..5, per-bucket start index. Default 0 (separate block from case 0).

class GoalUnlock_GFU {
public:
    int GetFirstUnlockVar(int type);
};

int GoalUnlock_GFU::GetFirstUnlockVar(int type) {
    switch (type) {
        case 0: return 0;
        case 1: return 31;
        case 2: return 4;
        case 3: return 7;
        case 4: return 11;
        case 5: return 15;
    }
    return 0;
}
