/* EIPointAmbLight::GetTypeInfo(void) const - 0x80229C44 (12 bytes) */
// TU: e_ipointamblight

struct TypeInfo;

extern TypeInfo EIPointAmbLight_typeInfo;

struct EIPointAmbLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIPointAmbLight::GetTypeInfo() const {
    return &EIPointAmbLight_typeInfo;
}
