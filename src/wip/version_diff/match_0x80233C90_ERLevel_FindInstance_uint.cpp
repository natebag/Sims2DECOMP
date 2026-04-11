struct EInstance;

struct EHashTable {
    int Find(unsigned int, unsigned int *) const;
};

struct ERLevel {
    char pad0[0x2A264];
    EHashTable m_idMap;

    EInstance *FindInstance(unsigned int id);
};

EInstance *ERLevel::FindInstance(unsigned int id) {
    EInstance *result;
    int found = m_idMap.Find(id, (unsigned int *)&result);
    if (found == 0) {
        return 0;
    }
    return result;
}
