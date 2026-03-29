/* EIPointLight::GetTypeVersion(void) const - 0x8022A584 (12 bytes) */
// TU: e_ipointlight

extern unsigned int EIPointLight_typeInfo_version;

struct EIPointLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EIPointLight::GetTypeVersion() const {
    return EIPointLight_typeInfo_version;
}
