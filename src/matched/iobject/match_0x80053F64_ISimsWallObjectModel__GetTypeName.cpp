// 0x80053F64 (12 bytes) - ISimsWallObjectModel::GetTypeName(void) const
// m_typeInfo.m_name @ +0x0C
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
    const char* GetTypeName() const;
};

const char* ISimsWallObjectModel::GetTypeName() const {
    return ISimsWallObjectModel__m_typeInfo.m_name;
}
