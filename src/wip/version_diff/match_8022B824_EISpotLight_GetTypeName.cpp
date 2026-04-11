/* EISpotLight::GetTypeName(void) const - 0x8022B824 (12 bytes) */
// TU: e_ispotlight

extern char EISpotLight_typeInfo_name;

struct EISpotLight {
    const char* GetTypeName() const;
};

const char* EISpotLight::GetTypeName() const {
    return &EISpotLight_typeInfo_name;
}
