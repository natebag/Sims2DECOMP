// 0x80054128 (12 bytes) - ISimsMultiTileObjectModel::GetReadVersion(void)
// m_typeInfo.m_readVersion @ +0x16 (unsigned -> lhz)
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
    unsigned short GetReadVersion();
};

unsigned short ISimsMultiTileObjectModel::GetReadVersion() {
    return ISimsMultiTileObjectModel__m_typeInfo.m_readVersion;
}
