// 0x80227814 match_80227814_EIGameInstance_GetTypeKey (12b)
// 0x80227814 EIGameInstance::GetTypeKey (12b)
// TU: e_igameinstance

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIGameInstance_typeInfo;

struct EIGameInstance {
    unsigned int GetTypeKey() const;
};

unsigned int EIGameInstance::GetTypeKey() const {
    return EIGameInstance_typeInfo.m_key;
}
