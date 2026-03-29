/* EIAmbLight::GetTypeInfo(void) const - 0x80226F1C (12 bytes) */
// TU: e_iamblight

struct TypeInfo;

extern TypeInfo EIAmbLight_typeInfo;

struct EIAmbLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIAmbLight::GetTypeInfo() const {
    return &EIAmbLight_typeInfo;
}
