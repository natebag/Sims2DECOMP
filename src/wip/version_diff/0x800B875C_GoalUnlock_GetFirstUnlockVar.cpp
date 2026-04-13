// FLAGS: -msdata=eabi -G 8
// 0x800B875C (112B)
// GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType)

struct GoalUnlock;

int GoalUnlock_GetFirstUnlockVar(GoalUnlock* self, int type) {
    switch (type) {
        case 0:
            return 0;
        case 1:
            return 31;
        case 2:
            return 4;
        case 4:
            return 11;
        case 5:
            return 15;
        default:
            return 0;
    }
}
