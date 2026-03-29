// 0x802293DC (12 bytes) - EInstance::GetReadVersion(void)
// lis r9,upper; lhz r3,lower(r9); blr

struct ETypeInfo_GRV { int data[6]; short extra; };
extern ETypeInfo_GRV EInstance_typeInfo_rv;

unsigned short EInstance_GetReadVersion() {
    return EInstance_typeInfo_rv.extra;
}
