/* EIPortalPointLight::GetTypeInfoStatic(void) - 0x8022B068 (12 bytes) */
// TU: e_iportalpointlight

struct TypeInfo;

extern TypeInfo EIPortalPointLight_typeInfo;

struct EIPortalPointLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIPortalPointLight::GetTypeInfoStatic() {
    return &EIPortalPointLight_typeInfo;
}
