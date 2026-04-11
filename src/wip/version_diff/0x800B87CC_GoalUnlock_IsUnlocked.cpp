// FLAGS: -msdata=eabi -G 8
// 0x800B87CC (180B)
// GoalUnlock::IsUnlocked(IGoalUnlock::UnlockType, short)

struct IGoalUnlock {
    virtual int GetUnlockCount(int type);
    virtual int GetFirstUnlockVar(int type);
    virtual int GetObjectIndexFromGuid(int guid);
    virtual int IsUnlocked(int type, short var);
    virtual void GrantUnlock(int type, short var);
    virtual int IsRecentlyUnlocked(int type, short var);
    virtual void SetRecentlyUnlocked(int type, short var, bool val);
    virtual int GetUnlockTotal(int type);
};

struct GoalUnlock {
    IGoalUnlock* m_vtable;
    short m_data[32];
};

extern int GetFirstUnlockVar(GoalUnlock* self, int type);

int GoalUnlock_IsUnlocked(GoalUnlock* self, int type, short var) {
    if (var < 0) return 0;
    
    // Virtual call: self->m_vtable->GetUnlockCount(type)
    int count = self->m_vtable->GetUnlockCount(type);
    if (var >= count) return 0;
    
    // Call GetFirstUnlockVar
    int firstVar = GetFirstUnlockVar(self, type);
    
    // Bit manipulation to check if unlocked
    int bitIdx = var + var;
    int wordIdx = bitIdx >> 4;
    int bitPos = bitIdx & 0xF;
    
    unsigned short* bits = (unsigned short*)((char*)self->m_data + wordIdx * 2 + wordIdx * 2);
    return (*bits >> bitPos) & 1;
}
