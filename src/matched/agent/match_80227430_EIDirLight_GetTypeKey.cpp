// 0x80227430 match_80227430_EIDirLight_GetTypeKey (12b)
// 0x80227430 EIDirLight::GetTypeKey (12b)
// TU: e_idirlight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIDirLight_typeInfo;

struct EIDirLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIDirLight::GetTypeKey() const {
    return EIDirLight_typeInfo.m_key;
}
