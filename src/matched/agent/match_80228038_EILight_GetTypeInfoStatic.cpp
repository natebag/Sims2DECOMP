// match_80228038_EILight_GetTypeInfoStatic.cpp
// Address: 0x80228038 | Size: 12 bytes
// Symbol: EILight::GetTypeInfoStatic(void)
// Pattern A: lis r3 + addi r3 → return address of global struct (free function, not method)

struct ETypeInfo_EILight_GTIS { int data[4]; };
extern ETypeInfo_EILight_GTIS lbl_EILight_TypeInfoStatic;

ETypeInfo_EILight_GTIS* EILight_GetTypeInfoStatic() {
    return &lbl_EILight_TypeInfoStatic;
}
