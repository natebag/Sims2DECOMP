// 0x80053F58 (12 bytes) - ISimsWallObjectModel::GetTypeInfo(void) const
// &m_typeInfo (returns base addr)
// FLAGS: -fno-schedule-insns

extern char ISimsWallObjectModel__m_typeInfo[];

class ISimsWallObjectModel {
public:
    char* GetTypeInfo() const;
};

char* ISimsWallObjectModel::GetTypeInfo() const {
    return ISimsWallObjectModel__m_typeInfo;
}
