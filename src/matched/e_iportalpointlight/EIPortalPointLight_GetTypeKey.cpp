// 0x8022B050 EIPortalPointLight::GetTypeKey (12b)
// TU: e_iportalpointlight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIPortalPointLight_typeInfo;

struct EIPortalPointLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPortalPointLight::GetTypeKey() const {
    return EIPortalPointLight_typeInfo.m_key;
}
