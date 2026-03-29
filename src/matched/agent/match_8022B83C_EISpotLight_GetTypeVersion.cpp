/* EISpotLight::GetTypeVersion(void) const - 0x8022B83C (12 bytes) */
// TU: e_ispotlight

extern unsigned int EISpotLight_typeInfo_version;

struct EISpotLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EISpotLight::GetTypeVersion() const {
    return EISpotLight_typeInfo_version;
}
