// ISimInstance::GetTypeInfoStatic(void)
// Address: 0x800568DC | Size: 12 bytes
// Same bytes as GetTypeInfo - returns &ISimInstance::m_typeInfo

struct ETypeInfo { int data[8]; };
extern ETypeInfo ISimInstance_m_typeInfo;

ETypeInfo *ISimInstance__GetTypeInfoStatic(void) {
    return &ISimInstance_m_typeInfo;
}
