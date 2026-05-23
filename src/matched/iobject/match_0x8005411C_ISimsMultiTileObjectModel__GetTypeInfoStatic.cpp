// 0x8005411C (12 bytes) - ISimsMultiTileObjectModel::GetTypeInfoStatic(void)
// &m_typeInfo (static, same bytes)
// FLAGS: -fno-schedule-insns

extern char ISimsMultiTileObjectModel__m_typeInfo[];

class ISimsMultiTileObjectModel {
public:
    static char* GetTypeInfoStatic();
};

char* ISimsMultiTileObjectModel::GetTypeInfoStatic() {
    return ISimsMultiTileObjectModel__m_typeInfo;
}
