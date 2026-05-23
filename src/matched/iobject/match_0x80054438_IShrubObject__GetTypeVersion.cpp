// 0x80054438 (12 bytes) - IShrubObject::GetTypeVersion(void) const
// m_typeInfo.m_version @ +0x14 (unsigned -> lhz)
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
    unsigned short GetTypeVersion() const;
};

unsigned short IShrubObject::GetTypeVersion() const {
    return IShrubObject__m_typeInfo.m_version;
}
