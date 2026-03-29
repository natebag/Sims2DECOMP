/* EIPointAmbLight::GetTypeInfoStatic(void) - 0x80229C74 (12 bytes) */
// TU: e_ipointamblight

struct TypeInfo;

extern TypeInfo EIPointAmbLight_typeInfo;

struct EIPointAmbLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIPointAmbLight::GetTypeInfoStatic() {
    return &EIPointAmbLight_typeInfo;
}
