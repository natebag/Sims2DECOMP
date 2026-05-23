// 0x80053CEC (12 bytes) - ISimsObjectModel::GetTypeName(void) const
// Reads m_typeInfo.m_name (offset +0xC).
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
    const char* GetTypeName() const;
};

const char* ISimsObjectModel::GetTypeName() const {
    return ISimsObjectModel__m_typeInfo.m_name;
}
