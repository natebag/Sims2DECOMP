// 0x80053F70 (12 bytes) - ISimsWallObjectModel::GetTypeKey(void) const
// m_typeInfo.m_key  @ +0x10
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
    int GetTypeKey() const;
};

int ISimsWallObjectModel::GetTypeKey() const {
    return ISimsWallObjectModel__m_typeInfo.m_key;
}
