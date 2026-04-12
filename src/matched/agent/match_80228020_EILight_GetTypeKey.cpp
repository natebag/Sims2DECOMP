// 0x80228020 match_80228020_EILight_GetTypeKey (12b)
// 0x80228020 EILight::GetTypeKey (12b)
// TU: e_ilight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EILight_typeInfo;

struct EILight {
    unsigned int GetTypeKey() const;
};

unsigned int EILight::GetTypeKey() const {
    return EILight_typeInfo.m_key;
}
