/* EIAmbLight::GetTypeVersion(void) const - 0x80226F40 (12 bytes) */
// TU: e_iamblight

extern unsigned int EIAmbLight_typeInfo_version;

struct EIAmbLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EIAmbLight::GetTypeVersion() const {
    return EIAmbLight_typeInfo_version;
}
