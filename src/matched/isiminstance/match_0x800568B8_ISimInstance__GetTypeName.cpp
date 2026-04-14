// 0x800568B8 ISimInstance::GetTypeName (12B) const

extern char* g_ISimInstance_TypeName[3];

struct ISimInstance_GetTypeName {
    const char* GetTypeName() const;
};

const char* ISimInstance_GetTypeName::GetTypeName() const {
    return g_ISimInstance_TypeName[0];
}
