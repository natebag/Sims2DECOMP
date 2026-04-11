/* EILight::GetTypeKey(void) const - 0x80228020 (12 bytes) */
// TU: e_ilight

extern unsigned int EILight_typeInfo_key;

struct EILight {
    unsigned int GetTypeKey() const;
};

unsigned int EILight::GetTypeKey() const {
    return EILight_typeInfo_key;
}
