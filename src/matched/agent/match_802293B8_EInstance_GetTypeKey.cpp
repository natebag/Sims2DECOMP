// 0x802293B8 match_802293B8_EInstance_GetTypeKey (12b)
// 0x802293B8 EInstance::GetTypeKey (12b)
// TU: e_instance

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EInstance_typeInfo;

struct EInstance {
    unsigned int GetTypeKey() const;
};

unsigned int EInstance::GetTypeKey() const {
    return EInstance_typeInfo.m_key;
}
