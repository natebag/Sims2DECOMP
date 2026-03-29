// 0x802293C4 (12 bytes) - EInstance::GetTypeVersion(void) const
// lis r9,upper; lhz r3,lower(r9); blr

struct ETypeInfo_GTV { int data[6]; };
extern ETypeInfo_GTV EInstance_typeInfo_ver;

struct EInstance_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short EInstance_GTV::GetTypeVersion() const {
    return *(unsigned short*)&EInstance_typeInfo_ver.data[5];
}
