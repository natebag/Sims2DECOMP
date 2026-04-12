// 0x8022B044 match_8022B044_EIPortalPointLight_GetTypeName (12b)
// 0x8022B044 EIPortalPointLight::GetTypeName (12b)
// TU: e_iportalpointlight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIPortalPointLight_typeInfo;

struct EIPortalPointLight {
    const char* GetTypeName() const;
};

const char* EIPortalPointLight::GetTypeName() const {
    return EIPortalPointLight_typeInfo.m_name;
}
