// 0x800568AC ISimInstance::GetTypeInfo (12b)

struct TypeInfo {
    char _pad[8];
};

extern TypeInfo g_ISimInstance_typeInfo;

struct ISimInstance {
    virtual TypeInfo* GetTypeInfo() const;
};

TypeInfo* ISimInstance::GetTypeInfo() const {
    return &g_ISimInstance_typeInfo;
}
