// 0x800542A4 (12 bytes) - ISimsCounterTopObject::GetTypeVersion(void) const
// m_typeInfo.m_version @ +0x14 (unsigned -> lhz)
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
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsCounterTopObject::GetTypeVersion() const {
    return ISimsCounterTopObject__m_typeInfo.m_version;
}
