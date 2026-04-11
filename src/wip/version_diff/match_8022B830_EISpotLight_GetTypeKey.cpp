/* EISpotLight::GetTypeKey(void) const - 0x8022B830 (12 bytes) */
// TU: e_ispotlight

extern unsigned int EISpotLight_typeInfo_key;

struct EISpotLight {
    unsigned int GetTypeKey() const;
};

unsigned int EISpotLight::GetTypeKey() const {
    return EISpotLight_typeInfo_key;
}
