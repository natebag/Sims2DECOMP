/* EISpotLight::GetTypeInfoStatic(void) - 0x8022B848 (12 bytes) */
// TU: e_ispotlight

struct TypeInfo;

extern TypeInfo EISpotLight_typeInfo;

struct EISpotLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EISpotLight::GetTypeInfoStatic() {
    return &EISpotLight_typeInfo;
}
