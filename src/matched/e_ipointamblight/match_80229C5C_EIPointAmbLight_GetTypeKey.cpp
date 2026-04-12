// 0x80229C5C EIPointAmbLight::GetTypeKey (12b)
// TU: e_ipointamblight

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIPointAmbLight_typeInfo;

struct EIPointAmbLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPointAmbLight::GetTypeKey() const {
    return EIPointAmbLight_typeInfo.m_key;
}
