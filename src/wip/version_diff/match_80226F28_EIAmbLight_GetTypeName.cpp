// 0x80226F28 EIAmbLight::GetTypeName (12b)
// TU: e_iamblight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIAmbLight_typeInfo;

struct EIAmbLight {
    const char* GetTypeName() const;
};

const char* EIAmbLight::GetTypeName() const {
    return EIAmbLight_typeInfo.m_name;
}
