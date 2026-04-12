// 0x80228014 EILight::GetTypeName (12b)
// TU: e_ilight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EILight_typeInfo;

struct EILight {
    const char* GetTypeName() const;
};

const char* EILight::GetTypeName() const {
    return EILight_typeInfo.m_name;
}
