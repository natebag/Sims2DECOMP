/* EILight::GetTypeInfo(void) const - 0x80228008 (12 bytes) */
// TU: e_ilight

struct TypeInfo;

extern TypeInfo EILight_typeInfo;

struct EILight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EILight::GetTypeInfo() const {
    return &EILight_typeInfo;
}
