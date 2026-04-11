/* EIPointLight::GetTypeName(void) const - 0x8022A56C (12 bytes) */
// TU: e_ipointlight

extern char EIPointLight_typeInfo_name;

struct EIPointLight {
    const char* GetTypeName() const;
};

const char* EIPointLight::GetTypeName() const {
    return &EIPointLight_typeInfo_name;
}
