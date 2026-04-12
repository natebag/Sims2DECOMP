// 0x802293AC match_802293AC_EInstance_GetTypeName (12b)
// 0x802293AC EInstance::GetTypeName (12b)
// TU: e_instance

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EInstance_typeInfo;

struct EInstance {
    const char* GetTypeName() const;
};

const char* EInstance::GetTypeName() const {
    return EInstance_typeInfo.m_name;
}
