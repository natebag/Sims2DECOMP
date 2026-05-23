// 0x80054110 (12 bytes) - ISimsMultiTileObjectModel::GetTypeVersion(void) const
// m_typeInfo.m_version @ +0x14 (unsigned -> lhz)
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
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsMultiTileObjectModel::GetTypeVersion() const {
    return ISimsMultiTileObjectModel__m_typeInfo.m_version;
}
