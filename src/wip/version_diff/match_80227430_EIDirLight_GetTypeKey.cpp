/* EIDirLight::GetTypeKey(void) const - 0x80227430 (12 bytes) */
// TU: e_idirlight

extern unsigned int EIDirLight_typeInfo_key;

struct EIDirLight {
    unsigned int GetTypeKey() const;
};

unsigned int EIDirLight::GetTypeKey() const {
    return EIDirLight_typeInfo_key;
}
