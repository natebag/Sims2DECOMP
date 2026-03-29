/* EISpotLight::GetTypeInfo(void) const - 0x8022B818 (12 bytes) */
// TU: e_ispotlight

struct TypeInfo;

extern TypeInfo EISpotLight_typeInfo;

struct EISpotLight {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EISpotLight::GetTypeInfo() const {
    return &EISpotLight_typeInfo;
}
