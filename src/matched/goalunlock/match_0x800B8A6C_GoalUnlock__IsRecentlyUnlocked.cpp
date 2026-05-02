// FLAGS: -fno-rtti
// 0x800B8A6C (184B) GoalUnlock::IsRecentlyUnlocked(IGoalUnlock::UnlockType, short)

class IGoalUnlock {
public:
    enum UnlockType {
        kUnlockType_Objects = 0,
        kUnlockType_1       = 1,
        kUnlockType_2       = 2,
        kUnlockType_3       = 3,
        kUnlockType_4       = 4,
        kUnlockType_5       = 5,
    };

    virtual int GetObjectIndexFromGuid(int guid);
    virtual void ClearGoalsAndUnlocks();
    virtual int GetUnlockCount(UnlockType type);
    virtual int GetUnlockTotal(UnlockType type);
    virtual int IsUnlocked(UnlockType type, short index);
    virtual void GrantUnlock(UnlockType type, short index);
    virtual void GrantObjectUnlocks(int guid);
    virtual int IsRecentlyUnlocked(UnlockType type, short index);
    virtual void SetRecentlyUnlocked(UnlockType type, short index, bool recent);
    virtual void DoStream(void* buffer, int version);
    virtual ~IGoalUnlock();
};

class GoalUnlock : public IGoalUnlock {
public:
    unsigned char m_unlockData[128];

    virtual int GetObjectIndexFromGuid(int guid);
    virtual void ClearGoalsAndUnlocks();
    virtual int GetUnlockCount(UnlockType type);
    virtual int GetUnlockTotal(UnlockType type);
    virtual int IsUnlocked(UnlockType type, short index);
    virtual void GrantUnlock(UnlockType type, short index);
    virtual void GrantObjectUnlocks(int guid);
    virtual int IsRecentlyUnlocked(UnlockType type, short index);
    virtual void SetRecentlyUnlocked(UnlockType type, short index, bool recent);
    virtual void DoStream(void* buffer, int version);
    virtual ~GoalUnlock();

    int GetFirstUnlockVar(UnlockType type);
};

int GoalUnlock::IsRecentlyUnlocked(UnlockType type, short index) {
    int count;
    int firstVar;
    short s;
    int q;
    int r;
    char* data;
    int byteOffset;
    short word;
    unsigned short mask;

    if (index < 0) goto fail;
    count = GetUnlockCount(type);
    if (index >= count) goto fail;
    firstVar = GetFirstUnlockVar(type);
    s = index * 2 + 1;
    q = s / 16;
    r = s % 16;
    mask = 1 << r;
    data = (char*)m_unlockData;
    byteOffset = 2 * (firstVar + q);
    word = *(short*)(data + byteOffset);
    if (!(word & mask)) goto fail;
    return 1;
fail:
    return 0;
}
