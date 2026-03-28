struct HTIteratorPtrType;
struct EInstance;

struct EHashTable {
    int FindNext(HTIteratorPtrType *, unsigned int *) const;
};

struct ERLevel {
    char pad0[0x2A264];
    EHashTable m_idMap;

    int FindNextInstance(HTIteratorPtrType *iter, EInstance **out);
};

int ERLevel::FindNextInstance(HTIteratorPtrType *iter, EInstance **out) {
    return m_idMap.FindNext(iter, (unsigned int *)out);
}
