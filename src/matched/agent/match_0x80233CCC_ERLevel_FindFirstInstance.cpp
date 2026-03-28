struct HTIteratorPtrType;
struct EInstance;

struct EHashTable {
    int Find(unsigned int, unsigned int *) const;
    int FindNext(HTIteratorPtrType *, unsigned int *) const;
};

struct ERLevel {
    char pad0[0x2A264];
    EHashTable m_idMap;

    int FindFirstInstance(unsigned int id, EInstance **out);
    int FindNextInstance(HTIteratorPtrType *iter, EInstance **out);
};

int ERLevel::FindFirstInstance(unsigned int id, EInstance **out) {
    return m_idMap.Find(id, (unsigned int *)out);
}
