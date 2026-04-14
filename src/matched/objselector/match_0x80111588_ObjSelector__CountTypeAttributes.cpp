// 0x80111588 ObjSelector::CountTypeAttributes (96B)

struct CountResult {
    char pad[4];
    int m_count;
};

struct CountProviderVtbl {
    char pad[0xb0];
    short adj;
    void* func;
};

struct CountProvider {
    CountProviderVtbl* vtable;
};

struct TypeInfo {
    char pad[0x1c];
    int m_fallbackType;
    char pad2[0xb8 - 0x1c - 4];
    int m_attrType;
};

struct ObjSelector {
    char pad[0x38];
    TypeInfo* m_typeInfo;
    char pad2[0x50 - 0x38 - 4];
    CountProvider* m_countProvider;
    
    int CountTypeAttributes();
};

int ObjSelector::CountTypeAttributes() {
    int attrType = m_typeInfo->m_attrType;
    if (attrType == 0) {
        attrType = m_typeInfo->m_fallbackType;
    }
    CountProviderVtbl* vt = m_countProvider->vtable;
    short adj = vt->adj;
    void* fn = vt->func;
    typedef CountResult* (*GetCountFunc)(void*, int);
    GetCountFunc f = (GetCountFunc)fn;
    CountResult* result = f((char*)m_countProvider + adj, attrType);
    if (result == 0) return 0;
    return result->m_count;
}
