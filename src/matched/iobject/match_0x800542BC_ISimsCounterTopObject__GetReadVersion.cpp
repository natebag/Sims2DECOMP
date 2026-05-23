// 0x800542BC (12 bytes) - ISimsCounterTopObject::GetReadVersion(void)
// m_typeInfo.m_readVersion @ +0x16 (unsigned -> lhz)
// FLAGS: -fno-schedule-insns

struct ISimsTypeInfo {
    char pad_0[0xC];
    const char* m_name;
    int m_key;
    unsigned short m_version;
    unsigned short m_readVersion;
};

extern ISimsTypeInfo ISimsCounterTopObject__m_typeInfo;

class ISimsCounterTopObject {
public:
    unsigned short GetReadVersion();
};

unsigned short ISimsCounterTopObject::GetReadVersion() {
    return ISimsCounterTopObject__m_typeInfo.m_readVersion;
}
