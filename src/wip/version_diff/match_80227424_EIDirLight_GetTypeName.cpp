/* EIDirLight::GetTypeName(void) const - 0x80227424 (12 bytes) */
// TU: e_idirlight

extern char EIDirLight_typeInfo_name;

struct EIDirLight {
    const char* GetTypeName() const;
};

const char* EIDirLight::GetTypeName() const {
    return &EIDirLight_typeInfo_name;
}
