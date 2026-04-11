/* EIAmbLight::GetReadVersion(void) - 0x80226F58 (12 bytes) */
// TU: e_iamblight

extern unsigned int EIAmbLight_readVersion;

struct EIAmbLight {
    static unsigned int GetReadVersion();
};

unsigned int EIAmbLight::GetReadVersion() {
    return EIAmbLight_readVersion;
}
