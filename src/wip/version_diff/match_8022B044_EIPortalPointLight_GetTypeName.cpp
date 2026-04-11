/* EIPortalPointLight::GetTypeName(void) const - 0x8022B044 (12 bytes) */
// TU: e_iportalpointlight

extern char EIPortalPointLight_typeInfo_name;

struct EIPortalPointLight {
    const char* GetTypeName() const;
};

const char* EIPortalPointLight::GetTypeName() const {
    return &EIPortalPointLight_typeInfo_name;
}
