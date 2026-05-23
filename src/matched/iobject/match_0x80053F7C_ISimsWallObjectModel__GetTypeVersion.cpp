// 0x80053F7C (12 bytes) - ISimsWallObjectModel::GetTypeVersion(void) const
// m_typeInfo.m_version @ +0x14 (unsigned -> lhz)
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
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsWallObjectModel::GetTypeVersion() const {
    return ISimsWallObjectModel__m_typeInfo.m_version;
}
