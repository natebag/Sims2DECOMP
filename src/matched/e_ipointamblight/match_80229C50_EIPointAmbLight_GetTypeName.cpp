// 0x80229C50 EIPointAmbLight::GetTypeName (12b)
// TU: e_ipointamblight

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIPointAmbLight_typeInfo;

struct EIPointAmbLight {
    const char* GetTypeName() const;
};

const char* EIPointAmbLight::GetTypeName() const {
    return EIPointAmbLight_typeInfo.m_name;
}
