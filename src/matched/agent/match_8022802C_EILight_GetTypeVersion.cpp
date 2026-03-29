// match_8022802C_EILight_GetTypeVersion.cpp
// Address: 0x8022802C | Size: 12 bytes
// Symbol: EILight::GetTypeVersion(void) const
// Pattern C: lis r9 + lhz r3 → return unsigned short from global (offset +20, index 5)

struct ETypeInfo_EILight_GTV { int data[6]; };
extern ETypeInfo_EILight_GTV lbl_EILight_TypeInfo_Version;

struct EILight_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short EILight_GTV::GetTypeVersion() const {
    return *(unsigned short*)&lbl_EILight_TypeInfo_Version.data[5];
}
