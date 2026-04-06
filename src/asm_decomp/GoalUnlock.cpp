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
class ReconBuffer;
class IGoalUnlock;

// Virtual base class with proper vtable layout
struct IGoalUnlock {
    virtual int GetUnlockCount(IGoalUnlock* self, int type);
    virtual int GetFirstUnlockVar(IGoalUnlock* self, int type);
    virtual int GetObjectIndexFromGuid(IGoalUnlock* self, int guid);
    virtual int IsUnlocked(IGoalUnlock* self, int type, short var);
    virtual void GrantUnlock(IGoalUnlock* self, int type, short var);
    virtual int IsRecentlyUnlocked(IGoalUnlock* self, int type, short var);
    virtual void SetRecentlyUnlocked(IGoalUnlock* self, int type, short var, bool val);
    virtual int GetUnlockTotal(IGoalUnlock* self, int type);
    virtual int DoStream(IGoalUnlock* self, ReconBuffer* buf, int val);
    virtual void GrantObjectUnlocks(IGoalUnlock* self, int val);
};

class GoalUnlock {
public:
    IGoalUnlock* m_vtable;
    
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
