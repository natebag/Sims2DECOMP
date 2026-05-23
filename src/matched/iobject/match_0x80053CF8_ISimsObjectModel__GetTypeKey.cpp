// 0x80053CF8 (12 bytes) - ISimsObjectModel::GetTypeKey(void) const
// Reads m_typeInfo.m_key (offset +0x10).
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
    int GetTypeKey() const;
};

int ISimsObjectModel::GetTypeKey() const {
    return ISimsObjectModel__m_typeInfo.m_key;
}
