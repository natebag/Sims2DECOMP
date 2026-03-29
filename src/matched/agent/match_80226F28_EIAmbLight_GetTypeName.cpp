/* EIAmbLight::GetTypeName(void) const - 0x80226F28 (12 bytes) */
// TU: e_iamblight

extern char EIAmbLight_typeInfo_name;

struct EIAmbLight {
    const char* GetTypeName() const;
};

const char* EIAmbLight::GetTypeName() const {
    return &EIAmbLight_typeInfo_name;
}
