// FLAGS: -fno-elide-constructors
/* 0x80233B9C (60 bytes) - ERLevel::AddInstanceToIdMap(EInstance*) */
struct EInstance {
    char pad[0x58];
    unsigned int m_id;
};

struct EHashTable {
    void Insert(unsigned int key, unsigned int val, int replace);
};

struct ERLevel {
    char pad0[0x2A264];
    EHashTable m_idMap;

    void AddInstanceToIdMap(EInstance *inst);
};

void ERLevel::AddInstanceToIdMap(EInstance *inst) {
    unsigned int id = inst->m_id;
    if (id != 0) {
        m_idMap.Insert(id, (unsigned int)inst, 1);
    }
}
