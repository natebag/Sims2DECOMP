// 0x800568AC ISimInstance::GetTypeInfo (12B) const

struct TypeInfo_ISimInstance { char data[256]; };
extern TypeInfo_ISimInstance g_ISimInstance_TypeInfo[3];

struct ISimInstance_GTI {
    TypeInfo_ISimInstance* GetTypeInfo() const;
};

TypeInfo_ISimInstance* ISimInstance_GTI::GetTypeInfo() const {
    return &g_ISimInstance_TypeInfo[0];
}
