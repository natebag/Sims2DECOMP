/* EIAmbLight::GetTypeKey(void) const - 0x80226F34 (12 bytes) */
// TU: e_iamblight

extern unsigned int EIAmbLight_typeInfo_key;

struct EIAmbLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIAmbLight::GetTypeKey() const {
    return EIAmbLight_typeInfo_key;
}
