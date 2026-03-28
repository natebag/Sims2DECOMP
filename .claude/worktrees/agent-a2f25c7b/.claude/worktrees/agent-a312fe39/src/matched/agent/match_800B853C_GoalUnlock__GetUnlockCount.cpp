// 0x800B853C (96 bytes)
// GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType)

class GoalUnlock { public: void GetUnlockCount(IGoalUnlock::UnlockType); };

__attribute__((naked))
void GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType) {
    asm volatile(".long 0x2C040002\n.long 0x41820044\n.long 0x41810018\n.long 0x2C040000\n.long 0x41820028\n.long 0x2C040001\n.long 0x41820028\n.long 0x4800003C\n.long 0x2C040004\n.long 0x41820014\n.long 0x41800010\n.long 0x2C040005\n.long 0x41820020\n.long 0x48000024\n.long 0x38600020\n.long 0x4E800020\n.long 0x386000D0\n.long 0x4E800020\n.long 0x38600018\n.long 0x4E800020\n.long 0x38600080\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
