/* 0x800B86D8 (132 bytes)
   GoalUnlock::GetObjectIndexFromGuid(int) */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct IGoalUnlock {
    virtual int V0(int);
    virtual int V1(int);
    virtual int GetObjectIndexFromGuid(int guid);
    virtual int V3(int, s16);
    virtual void V4(int, s16);
    virtual int V5(int, s16);
    virtual void V6(int, s16, bool);
    virtual int GetUnlockTotal(int type);
};

struct GuidEntry {
    u32 guid;
    u32 pad;
};

extern GuidEntry g_GuidTable[];

struct GoalUnlock {
    IGoalUnlock* m_vtable;
    s16 m_data[32];
    
    int GetObjectIndexFromGuid(int guid);
};

int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    for (s16 i = 0; i < (s16)m_vtable->GetUnlockTotal(5); i++) {
        if (g_GuidTable[i].guid == guid) {
            return i;
        }
    }
    return -1;
}
