// match_80228008_EILight_GetTypeInfo.cpp
// Address: 0x80228008 | Size: 12 bytes
// Symbol: EILight::GetTypeInfo(void) const
// Pattern A: lis r3 + addi r3 → return address of global struct

struct ETypeInfo_EILight_GTI { int data[4]; };
extern ETypeInfo_EILight_GTI lbl_EILight_TypeInfo;

struct EILight {
    ETypeInfo_EILight_GTI* GetTypeInfo() const;
};

ETypeInfo_EILight_GTI* EILight::GetTypeInfo() const {
    return &lbl_EILight_TypeInfo;
}
