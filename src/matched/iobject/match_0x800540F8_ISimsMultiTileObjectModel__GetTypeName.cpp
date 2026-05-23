// 0x800540F8 (12 bytes) - ISimsMultiTileObjectModel::GetTypeName(void) const
// m_typeInfo.m_name @ +0x0C
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
    const char* GetTypeName() const;
};

const char* ISimsMultiTileObjectModel::GetTypeName() const {
    return ISimsMultiTileObjectModel__m_typeInfo.m_name;
}
