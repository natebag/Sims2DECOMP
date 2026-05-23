// 0x80053D04 (12 bytes) - ISimsObjectModel::GetTypeVersion(void) const
// Reads m_typeInfo.m_version (offset +0x14, halfword unsigned -> lhz).
// FLAGS: -fno-schedule-insns

struct ISimsTypeInfo {
    char pad_0[0xC];
    const char* m_name;
    int m_key;
    unsigned short m_version;
    unsigned short m_readVersion;
};

extern ISimsTypeInfo ISimsObjectModel__m_typeInfo;

class ISimsObjectModel {
public:
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsObjectModel::GetTypeVersion() const {
    return ISimsObjectModel__m_typeInfo.m_version;
}
