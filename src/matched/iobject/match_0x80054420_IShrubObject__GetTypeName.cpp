// 0x80054420 (12 bytes) - IShrubObject::GetTypeName(void) const
// m_typeInfo.m_name @ +0x0C
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
    const char* GetTypeName() const;
};

const char* IShrubObject::GetTypeName() const {
    return IShrubObject__m_typeInfo.m_name;
}
