// 0x801115E8 ObjSelector::GetTypeAttributes (92B)

struct TypeAttrResult {
    char pad[8];
    int m_typeAttr;
};

struct TypeAttrProviderVtbl {
    char pad[0xb0];
    short adj;
    void* func;
};

struct TypeAttrProvider {
    TypeAttrProviderVtbl* vtable;
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
    TypeAttrProvider* m_typeAttrProvider;
    
    int GetTypeAttributes();
};

int ObjSelector::GetTypeAttributes() {
    int attrType = m_typeInfo->m_attrType;
    if (attrType == 0) {
        attrType = m_typeInfo->m_fallbackType;
    }
    TypeAttrProviderVtbl* vt = m_typeAttrProvider->vtable;
    short adj = vt->adj;
    void* fn = vt->func;
    typedef TypeAttrResult* (*GetTypeAttrFunc)(void*, int);
    GetTypeAttrFunc f = (GetTypeAttrFunc)fn;
    TypeAttrResult* result = f((char*)m_typeAttrProvider + adj, attrType);
    if (result == 0) return 0;
    return result->m_typeAttr;
}
