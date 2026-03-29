/* EIDirLight::GetTypeVersion(void) const - 0x8022743C (12 bytes) */
// TU: e_idirlight

extern unsigned int EIDirLight_typeInfo_version;

struct EIDirLight {
    unsigned int GetTypeVersion() const;
};

unsigned int EIDirLight::GetTypeVersion() const {
    return EIDirLight_typeInfo_version;
}
