// 0x80227424 match_80227424_EIDirLight_GetTypeName (12b)
// 0x80227424 EIDirLight::GetTypeName (12b)
// TU: e_idirlight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIDirLight_typeInfo;

struct EIDirLight {
    const char* GetTypeName() const;
};

const char* EIDirLight::GetTypeName() const {
    return EIDirLight_typeInfo.m_name;
}
