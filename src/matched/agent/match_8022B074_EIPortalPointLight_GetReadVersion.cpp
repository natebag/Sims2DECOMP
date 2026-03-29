/* EIPortalPointLight::GetReadVersion(void) - 0x8022B074 (12 bytes) */
// TU: e_iportalpointlight

extern unsigned int EIPortalPointLight_readVersion;

struct EIPortalPointLight {
    static unsigned int GetReadVersion();
};

unsigned int EIPortalPointLight::GetReadVersion() {
    return EIPortalPointLight_readVersion;
}
