/* 0x800B8A6C (184 bytes)
   GoalUnlock::IsRecentlyUnlocked(IGoalUnlock::UnlockType, short) */

typedef signed short s16;

struct IGoalUnlock {
    virtual int V0(int);
    virtual int V1(int);
    virtual int V2(int);
    virtual int V3(int, s16);
    virtual void V4(int, s16);
    virtual int IsRecentlyUnlocked(int type, s16 var);
    virtual void V6(int, s16, bool);
    virtual int GetUnlockTotal(int type);
};

struct GoalUnlock {
    IGoalUnlock* m_vtable;
    s16 m_data[32];
    
    int IsRecentlyUnlocked(int type, s16 var);
};

int GoalUnlock::IsRecentlyUnlocked(int type, s16 var) {
    if (var < 0 || var >= (s16)m_vtable->GetUnlockTotal(type)) {
        return 0;
    }
    s16 wordIdx = (var + 1) >> 4;
    s16 bitIdx = (var + 1) & 0xF;
    return (m_data[wordIdx] >> bitIdx) & 1;
}
