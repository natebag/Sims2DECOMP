// 0x800B86D8 (132 bytes)
// GoalUnlock::GetObjectIndexFromGuid(int)

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct GuidEntry {
    u32 guid;
    u32 pad;
};

extern GuidEntry g_GuidTable[];

struct BaseGoalUnlock {
    virtual int V0(int);
    virtual int V1(int);
    virtual int GetUnlockTotal(int type);
};

struct GoalUnlock : BaseGoalUnlock {
    s16 m_data[32];
    
    int GetObjectIndexFromGuid(int guid);
};

int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    for (s16 i = 0; i < GetUnlockTotal(5); i++) {
        if (guid == g_GuidTable[i].guid) {
            return i;
        }
    }
    return -1;
}
