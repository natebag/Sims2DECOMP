/* EIPointAmbLight::GetTypeVersion(void) const - 0x80229C68 (12 bytes) */
// TU: e_ipointamblight

extern unsigned int EIPointAmbLight_typeInfo_version;

struct EIPointAmbLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EIPointAmbLight::GetTypeVersion() const {
    return EIPointAmbLight_typeInfo_version;
}
