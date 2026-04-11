/* EIPointLight::GetReadVersion(void) - 0x8022A59C (12 bytes) */
// TU: e_ipointlight

extern unsigned int EIPointLight_readVersion;

struct EIPointLight {
    static unsigned int GetReadVersion();
};

unsigned int EIPointLight::GetReadVersion() {
    return EIPointLight_readVersion;
}
