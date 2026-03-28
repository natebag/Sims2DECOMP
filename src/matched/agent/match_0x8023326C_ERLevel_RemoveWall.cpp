struct NLIteratorPtrType;

struct ENodeList {
    void Remove(NLIteratorPtrType *);
};

struct EInstance;

struct ERLevel {
    char pad0[0x2A298];
    ENodeList m_wallList;

    void RemoveInstance(EInstance *);
    void RemoveWall(EInstance *);
};

struct EInstance {
    char pad[0x78];
    NLIteratorPtrType *m_wallNode;
};

void ERLevel::RemoveWall(EInstance *inst) {
    NLIteratorPtrType *node = inst->m_wallNode;
    if (node != 0) {
        m_wallList.Remove(node);
    }
    inst->m_wallNode = 0;
    RemoveInstance(inst);
}
