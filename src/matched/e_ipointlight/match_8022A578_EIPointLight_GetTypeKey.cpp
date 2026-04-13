// 0x8022A578 EIPointLight::GetTypeKey (12b)
// TU: e_ipointlight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIPointLight_typeInfo;

struct EIPointLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPointLight::GetTypeKey() const {
    return EIPointLight_typeInfo.m_key;
}
