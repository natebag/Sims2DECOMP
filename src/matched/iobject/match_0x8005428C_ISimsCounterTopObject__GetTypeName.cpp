// 0x8005428C (12 bytes) - ISimsCounterTopObject::GetTypeName(void) const
// m_typeInfo.m_name @ +0x0C
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
    const char* GetTypeName() const;
};

const char* ISimsCounterTopObject::GetTypeName() const {
    return ISimsCounterTopObject__m_typeInfo.m_name;
}
