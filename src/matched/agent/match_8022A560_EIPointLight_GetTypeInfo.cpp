/* EIPointLight::GetTypeInfo(void) const - 0x8022A560 (12 bytes) */
// TU: e_ipointlight

struct TypeInfo;

extern TypeInfo EIPointLight_typeInfo;

struct EIPointLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIPointLight::GetTypeInfo() const {
    return &EIPointLight_typeInfo;
}
