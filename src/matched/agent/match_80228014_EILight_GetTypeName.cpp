/* EILight::GetTypeName(void) const - 0x80228014 (12 bytes) */
// TU: e_ilight

extern char EILight_typeInfo_name;

struct EILight {
    const char* GetTypeName() const;
};

const char* EILight::GetTypeName() const {
    return &EILight_typeInfo_name;
}
