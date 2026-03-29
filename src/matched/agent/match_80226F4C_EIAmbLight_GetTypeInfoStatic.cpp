/* EIAmbLight::GetTypeInfoStatic(void) - 0x80226F4C (12 bytes) */
// TU: e_iamblight

struct TypeInfo;

extern TypeInfo EIAmbLight_typeInfo;

struct EIAmbLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIAmbLight::GetTypeInfoStatic() {
    return &EIAmbLight_typeInfo;
}
