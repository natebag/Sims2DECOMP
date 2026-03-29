/* EILight::GetTypeVersion(void) const - 0x8022802C (12 bytes) */
// TU: e_ilight

extern unsigned int EILight_typeInfo_version;

struct EILight {
    unsigned int GetTypeVersion() const;
};

unsigned int EILight::GetTypeVersion() const {
    return EILight_typeInfo_version;
}
