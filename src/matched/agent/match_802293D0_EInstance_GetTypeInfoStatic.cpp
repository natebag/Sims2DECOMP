// 0x802293D0 (12 bytes) - EInstance::GetTypeInfoStatic(void)
// Same pattern as GetTypeInfo: lis r3,upper; addi r3,r3,lower; blr

struct ETypeInfo_GTIS { int data[4]; };
extern ETypeInfo_GTIS EInstance_typeInfo_static;

ETypeInfo_GTIS* EInstance_GetTypeInfoStatic() {
    return &EInstance_typeInfo_static;
}
