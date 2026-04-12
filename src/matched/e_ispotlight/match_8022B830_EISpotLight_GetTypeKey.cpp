// 0x8022B830 EISpotLight::GetTypeKey (12b)
// TU: e_ispotlight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EISpotLight_typeInfo;

struct EISpotLight {
    unsigned int GetTypeKey() const;
};

unsigned int EISpotLight::GetTypeKey() const {
    return EISpotLight_typeInfo.m_key;
}
