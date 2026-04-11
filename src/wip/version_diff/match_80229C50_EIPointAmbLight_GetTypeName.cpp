/* EIPointAmbLight::GetTypeName(void) const - 0x80229C50 (12 bytes) */
// TU: e_ipointamblight

extern char EIPointAmbLight_typeInfo_name;

struct EIPointAmbLight {
    const char* GetTypeName() const;
};

const char* EIPointAmbLight::GetTypeName() const {
    return &EIPointAmbLight_typeInfo_name;
}
