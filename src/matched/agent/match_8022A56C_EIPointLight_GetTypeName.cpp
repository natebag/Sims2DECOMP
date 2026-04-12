// 0x8022A56C match_8022A56C_EIPointLight_GetTypeName (12b)
// 0x8022A56C EIPointLight::GetTypeName (12b)
// TU: e_ipointlight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIPointLight_typeInfo;

struct EIPointLight {
    const char* GetTypeName() const;
};

const char* EIPointLight::GetTypeName() const {
    return EIPointLight_typeInfo.m_name;
}
