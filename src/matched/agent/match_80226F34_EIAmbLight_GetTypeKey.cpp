// 0x80226F34 match_80226F34_EIAmbLight_GetTypeKey (12b)
// 0x80226F34 EIAmbLight::GetTypeKey (12b)
// TU: e_iamblight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIAmbLight_typeInfo;

struct EIAmbLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIAmbLight::GetTypeKey() const {
    return EIAmbLight_typeInfo.m_key;
}
