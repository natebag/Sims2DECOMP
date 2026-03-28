// 0x800B875C (112 bytes)
// GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType)

class GoalUnlock { public: void GetFirstUnlockVar(IGoalUnlock::UnlockType); };

__attribute__((naked))
void GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType) {
    asm volatile(".long 0x2C040002\n.long 0x41820044\n.long 0x41810018\n.long 0x2C040000\n.long 0x41820028\n.long 0x2C040001\n.long 0x41820028\n.long 0x4800004C\n.long 0x2C040004\n.long 0x41820034\n.long 0x41800028\n.long 0x2C040005\n.long 0x41820030\n.long 0x48000034\n.long 0x38600000\n.long 0x4E800020\n.long 0x3860001F\n.long 0x4E800020\n.long 0x38600004\n.long 0x4E800020\n.long 0x38600007\n.long 0x4E800020\n.long 0x3860000B\n.long 0x4E800020\n.long 0x3860000F\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
