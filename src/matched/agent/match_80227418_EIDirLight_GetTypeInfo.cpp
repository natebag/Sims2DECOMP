/* EIDirLight::GetTypeInfo(void) const - 0x80227418 (12 bytes) */
// TU: e_idirlight

struct TypeInfo;

extern TypeInfo EIDirLight_typeInfo;

struct EIDirLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIDirLight::GetTypeInfo() const {
    return &EIDirLight_typeInfo;
}
