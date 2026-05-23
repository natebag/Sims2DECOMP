// 0x80053F88 (12 bytes) - ISimsWallObjectModel::GetTypeInfoStatic(void)
// &m_typeInfo (static, same bytes)
// FLAGS: -fno-schedule-insns

extern char ISimsWallObjectModel__m_typeInfo[];

class ISimsWallObjectModel {
public:
    static char* GetTypeInfoStatic();
};

char* ISimsWallObjectModel::GetTypeInfoStatic() {
    return ISimsWallObjectModel__m_typeInfo;
}
