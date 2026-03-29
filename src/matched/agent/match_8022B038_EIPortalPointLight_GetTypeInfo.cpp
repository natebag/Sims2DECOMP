/* EIPortalPointLight::GetTypeInfo(void) const - 0x8022B038 (12 bytes) */
// TU: e_iportalpointlight

struct TypeInfo;

extern TypeInfo EIPortalPointLight_typeInfo;

struct EIPortalPointLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIPortalPointLight::GetTypeInfo() const {
    return &EIPortalPointLight_typeInfo;
}
