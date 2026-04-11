/* EIPortalPointLight::GetTypeKey(void) const - 0x8022B050 (12 bytes) */
// TU: e_iportalpointlight

extern unsigned int EIPortalPointLight_typeInfo_key;

struct EIPortalPointLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPortalPointLight::GetTypeKey() const {
    return EIPortalPointLight_typeInfo_key;
}
