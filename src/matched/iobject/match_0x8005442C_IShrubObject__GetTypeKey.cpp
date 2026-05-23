// 0x8005442C (12 bytes) - IShrubObject::GetTypeKey(void) const
// m_typeInfo.m_key  @ +0x10
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
    int GetTypeKey() const;
};

int IShrubObject::GetTypeKey() const {
    return IShrubObject__m_typeInfo.m_key;
}
