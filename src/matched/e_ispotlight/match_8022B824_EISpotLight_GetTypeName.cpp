// 0x8022B824 EISpotLight::GetTypeName (12b)
// TU: e_ispotlight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EISpotLight_typeInfo;

struct EISpotLight {
    const char* GetTypeName() const;
};

const char* EISpotLight::GetTypeName() const {
    return EISpotLight_typeInfo.m_name;
}
