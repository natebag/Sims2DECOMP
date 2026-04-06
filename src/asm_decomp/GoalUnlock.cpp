// FLAGS: -msdata=eabi -G 8

// Basic types
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int BOOL;

// Forward declarations
struct ReconBuffer {
    void Recon16(short* data, int count);
};

struct IGoalUnlock {
    virtual int GetUnlockCount(int type);
    virtual int GetFirstUnlockVar(int type);
    virtual int GetObjectIndexFromGuid(int guid);
    virtual int IsUnlocked(int type, short var);
    virtual void GrantUnlock(int type, short var);
    virtual int IsRecentlyUnlocked(int type, short var);
    virtual void SetRecentlyUnlocked(int type, short var, bool val);
    virtual int GetUnlockTotal(int type);
    virtual int DoStream(ReconBuffer* buf, int val);
    virtual void GrantObjectUnlocks(int val);
};

struct GoalUnlock {
    IGoalUnlock* m_vtable;
    short m_data[32];
    
    GoalUnlock();
    ~GoalUnlock();
    
    int DoStream(ReconBuffer* buf, int val);
    int GetUnlockCount(int type);
    void SetupObjectUnlockInfo();
    int GetObjectIndexFromGuid(int guid);
    int GetFirstUnlockVar(int type);
    int IsUnlocked(int type, short var);
    void GrantUnlock(int type, short var);
    void GrantObjectUnlocks(int val);
    int IsRecentlyUnlocked(int type, short var);
    void SetRecentlyUnlocked(int type, short var, bool val);
    int GetUnlockTotal(int type);
    void ClearGoalsAndUnlocks();
};

// 0x800B853C (96 bytes)
// GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType)
int GoalUnlock::GetUnlockCount(int type) {
    switch (type) {
        case 0:
        case 4:
            return 32;
        case 1:
            return 208;
        case 2:
            return 24;
        case 5:
            return 128;
        default:
            return 0;
    }
}

// 0x800B875C (112 bytes)
// GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType)
int GoalUnlock::GetFirstUnlockVar(int type) {
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

// 0x800B86D8 (132 bytes)
// GoalUnlock::GetObjectIndexFromGuid(int)
struct GuidEntry {
    int guid;
    int pad;
};

extern GuidEntry g_GuidTable[];

int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    for (short i = 0; i < (short)m_vtable->GetUnlockTotal(5); i++) {
        if (g_GuidTable[i].guid == guid) {
            return i;
        }
    }
    return -1;
}

// 0x800B8A6C (184 bytes)
// GoalUnlock::IsRecentlyUnlocked(IGoalUnlock::UnlockType, short)
int GoalUnlock::IsRecentlyUnlocked(int type, short var) {
    if (var < 0 || var >= (short)m_vtable->GetUnlockTotal(type)) {
        return 0;
    }
    short wordIdx = (var + 1) >> 4;
    short bitIdx = (var + 1) & 0xF;
    return (m_data[wordIdx] >> bitIdx) & 1;
}
