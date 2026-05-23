// 0x80053F94 (12 bytes) - ISimsWallObjectModel::GetReadVersion(void)
// m_typeInfo.m_readVersion @ +0x16 (unsigned -> lhz)
// FLAGS: -fno-schedule-insns

struct ISimsTypeInfo {
    char pad_0[0xC];
    const char* m_name;
    int m_key;
    unsigned short m_version;
    unsigned short m_readVersion;
};

extern ISimsTypeInfo ISimsWallObjectModel__m_typeInfo;

class ISimsWallObjectModel {
public:
    unsigned short GetReadVersion();
};

unsigned short ISimsWallObjectModel::GetReadVersion() {
    return ISimsWallObjectModel__m_typeInfo.m_readVersion;
}
