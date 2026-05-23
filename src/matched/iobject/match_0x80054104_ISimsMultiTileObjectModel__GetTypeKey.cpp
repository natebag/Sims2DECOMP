// 0x80054104 (12 bytes) - ISimsMultiTileObjectModel::GetTypeKey(void) const
// m_typeInfo.m_key  @ +0x10
// FLAGS: -fno-schedule-insns

struct ISimsTypeInfo {
    char pad_0[0xC];
    const char* m_name;
    int m_key;
    unsigned short m_version;
    unsigned short m_readVersion;
};

extern ISimsTypeInfo ISimsMultiTileObjectModel__m_typeInfo;

class ISimsMultiTileObjectModel {
public:
    int GetTypeKey() const;
};

int ISimsMultiTileObjectModel::GetTypeKey() const {
    return ISimsMultiTileObjectModel__m_typeInfo.m_key;
}
