// 0x80053D1C (12 bytes) - ISimsObjectModel::GetReadVersion(void)
// Reads m_typeInfo.m_readVersion (offset +0x16, halfword unsigned -> lhz).
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
    unsigned short GetReadVersion();
};

unsigned short ISimsObjectModel::GetReadVersion() {
    return ISimsObjectModel__m_typeInfo.m_readVersion;
}
