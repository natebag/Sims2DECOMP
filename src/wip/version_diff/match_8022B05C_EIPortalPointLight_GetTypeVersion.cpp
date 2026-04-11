/* EIPortalPointLight::GetTypeVersion(void) const - 0x8022B05C (12 bytes) */
// TU: e_iportalpointlight

extern unsigned int EIPortalPointLight_typeInfo_version;

struct EIPortalPointLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EIPortalPointLight::GetTypeVersion() const {
    return EIPortalPointLight_typeInfo_version;
}
