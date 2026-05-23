// 0x80054298 (12 bytes) - ISimsCounterTopObject::GetTypeKey(void) const
// m_typeInfo.m_key  @ +0x10
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
    int GetTypeKey() const;
};

int ISimsCounterTopObject::GetTypeKey() const {
    return ISimsCounterTopObject__m_typeInfo.m_key;
}
