/* EIPointLight::GetTypeKey(void) const - 0x8022A578 (12 bytes) */
// TU: e_ipointlight

extern unsigned int EIPointLight_typeInfo_key;

struct EIPointLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPointLight::GetTypeKey() const {
    return EIPointLight_typeInfo_key;
}
