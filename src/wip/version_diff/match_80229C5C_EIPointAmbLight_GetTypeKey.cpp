/* EIPointAmbLight::GetTypeKey(void) const - 0x80229C5C (12 bytes) */
// TU: e_ipointamblight

extern unsigned int EIPointAmbLight_typeInfo_key;

struct EIPointAmbLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIPointAmbLight::GetTypeKey() const {
    return EIPointAmbLight_typeInfo_key;
}
