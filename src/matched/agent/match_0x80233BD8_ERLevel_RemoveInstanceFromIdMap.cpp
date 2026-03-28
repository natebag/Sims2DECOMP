typedef unsigned int uint32;
struct HTIteratorPtrType;

struct EInstance {
    char pad[0x58];
    uint32 m_id;
};

struct EHashTable {
    int Find(uint32 key, uint32 *out) const;
    int FindNext(HTIteratorPtrType *iter, uint32 *out) const;
    void Remove(HTIteratorPtrType *iter);
};

struct ERLevel {
    char pad0[0x2A264];
    EHashTable m_idMap;

    void RemoveInstanceFromIdMap(EInstance *inst);
};

void ERLevel::RemoveInstanceFromIdMap(EInstance *inst) {
    uint32 id = inst->m_id;
    if (id == 0) return;

    uint32 result;
    HTIteratorPtrType *iter;
    iter = (HTIteratorPtrType *)m_idMap.Find(id, &result);
    while (1) {
        if (iter == 0) break;
        if (result == (uint32)inst) {
            m_idMap.Remove(iter);
            break;
        }
        iter = (HTIteratorPtrType *)m_idMap.FindNext(iter, &result);
    }
}
