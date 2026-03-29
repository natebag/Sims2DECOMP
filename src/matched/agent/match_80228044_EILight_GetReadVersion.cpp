/* EILight::GetReadVersion(void) - 0x80228044 (12 bytes) */
// TU: e_ilight

extern unsigned int EILight_readVersion;

struct EILight {
    static unsigned int GetReadVersion();
};

unsigned int EILight::GetReadVersion() {
    return EILight_readVersion;
}
