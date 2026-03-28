typedef unsigned int uint32;

struct ENodeList {
    uint32 AddTail(uint32);
};

struct EInstance;

struct ERLevel {
    char pad0[0x2A298];
    ENodeList m_wallList;

    void InsertInstance(EInstance *, EInstance *);
    void InsertWall(EInstance *, int);
};

struct EInstance {
    char pad[0x78];
    int m_wallIndex;
};

void ERLevel::InsertWall(EInstance *inst, int isWall) {
    InsertInstance(inst, 0);
    if (isWall != 0) {
        int idx = m_wallList.AddTail((uint32)inst);
        inst->m_wallIndex = idx;
    } else {
        inst->m_wallIndex = isWall;
    }
}
