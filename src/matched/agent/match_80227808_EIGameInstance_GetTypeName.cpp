// 0x80227808 match_80227808_EIGameInstance_GetTypeName (12b)
// 0x80227808 EIGameInstance::GetTypeName (12b)
// TU: e_igameinstance

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIGameInstance_typeInfo;

struct EIGameInstance {
    const char* GetTypeName() const;
};

const char* EIGameInstance::GetTypeName() const {
    return EIGameInstance_typeInfo.m_name;
}
