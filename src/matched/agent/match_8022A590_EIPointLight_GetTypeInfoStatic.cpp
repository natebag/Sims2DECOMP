/* EIPointLight::GetTypeInfoStatic(void) - 0x8022A590 (12 bytes) */
// TU: e_ipointlight

struct TypeInfo;

extern TypeInfo EIPointLight_typeInfo;

struct EIPointLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIPointLight::GetTypeInfoStatic() {
    return &EIPointLight_typeInfo;
}
