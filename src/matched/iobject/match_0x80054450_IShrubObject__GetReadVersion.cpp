// 0x80054450 (12 bytes) - IShrubObject::GetReadVersion(void)
// m_typeInfo.m_readVersion @ +0x16 (unsigned -> lhz)
// FLAGS: -fno-schedule-insns

struct ISimsTypeInfo {
    char pad_0[0xC];
    const char* m_name;
    int m_key;
    unsigned short m_version;
    unsigned short m_readVersion;
};

extern ISimsTypeInfo IShrubObject__m_typeInfo;

class IShrubObject {
public:
    unsigned short GetReadVersion();
};

unsigned short IShrubObject::GetReadVersion() {
    return IShrubObject__m_typeInfo.m_readVersion;
}
