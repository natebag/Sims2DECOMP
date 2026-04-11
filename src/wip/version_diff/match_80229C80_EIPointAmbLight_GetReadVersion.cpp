/* EIPointAmbLight::GetReadVersion(void) - 0x80229C80 (12 bytes) */
// TU: e_ipointamblight

extern unsigned int EIPointAmbLight_readVersion;

struct EIPointAmbLight {
    static unsigned int GetReadVersion();
};

unsigned int EIPointAmbLight::GetReadVersion() {
    return EIPointAmbLight_readVersion;
}
