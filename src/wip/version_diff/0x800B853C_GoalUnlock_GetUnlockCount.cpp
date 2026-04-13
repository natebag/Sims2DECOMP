// FLAGS: -msdata=eabi -G 8
// 0x800B853C (96B)
// GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType)
// DOL layout: cmp 2, beq->48, bgt->20, cmp 0, beq->38, cmp 1, beq->40, b->58
//             cmp 4, beq->38, blt->38, cmp 5, beq->50, b->58

struct GoalUnlock;

int GoalUnlock_GetUnlockCount(GoalUnlock* self, int type) {
    // Type 2 first (offset 0x48)
    if (type == 2) return 24;
    
    // Types > 2 (offset 0x20)
    if (type > 2) {
        // Type 4 (offset 0x38 via beq)
        if (type == 4) return 32;
        // Type < 4 (i.e., type == 3) also goes to offset 0x38 via blt
        // Need to use comparison that generates blt instead of cmpwi/ble
        if (type < 4) return 32;
        // Type 5 (offset 0x50)
        if (type == 5) return 128;
        // Default (offset 0x58)
        return 0;
    }
    
    // Types < 2
    if (type == 0) return 32;   // Offset 0x38
    if (type == 1) return 208;  // Offset 0x40
    return 0;                    // Offset 0x58
}
