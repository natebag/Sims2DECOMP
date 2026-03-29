// 0x802293A0 (12 bytes) - EInstance::GetTypeInfo(void) const
// lis r3,upper; addi r3,r3,lower; blr
// Returns address of static ETypeInfo struct (>8 bytes to avoid SDA)

struct ETypeInfo_GTI { int data[4]; };
extern ETypeInfo_GTI EInstance_typeInfo_data;

struct EInstance_GTI {
    ETypeInfo_GTI* GetTypeInfo() const;
};

ETypeInfo_GTI* EInstance_GTI::GetTypeInfo() const {
    return &EInstance_typeInfo_data;
}
