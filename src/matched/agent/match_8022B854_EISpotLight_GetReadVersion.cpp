/* EISpotLight::GetReadVersion(void) - 0x8022B854 (12 bytes) */
// TU: e_ispotlight

extern unsigned int EISpotLight_readVersion;

struct EISpotLight {
    static unsigned int GetReadVersion();
};

unsigned int EISpotLight::GetReadVersion() {
    return EISpotLight_readVersion;
}
