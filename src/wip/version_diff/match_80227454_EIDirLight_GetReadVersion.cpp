/* EIDirLight::GetReadVersion(void) - 0x80227454 (12 bytes) */
// TU: e_idirlight

extern unsigned int EIDirLight_readVersion;

struct EIDirLight {
    static unsigned int GetReadVersion();
};

unsigned int EIDirLight::GetReadVersion() {
    return EIDirLight_readVersion;
}
