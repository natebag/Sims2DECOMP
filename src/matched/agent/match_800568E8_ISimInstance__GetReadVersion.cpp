// ISimInstance::GetReadVersion(void)
// Address: 0x800568E8 | Size: 12 bytes
// lhz r3, -19354(r9) where r9 = lis 0x8050 => loads halfword from 0x804FB466

struct ETypeInfo {
    int data[4];
    int data2[4];
    unsigned short readVersion;  // at offset 0x16
};
extern ETypeInfo ISimInstance_m_typeInfo;

unsigned short ISimInstance__GetReadVersion(void) {
    return ISimInstance_m_typeInfo.readVersion;
}
