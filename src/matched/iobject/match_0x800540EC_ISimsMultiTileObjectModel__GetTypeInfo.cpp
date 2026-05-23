// 0x800540EC (12 bytes) - ISimsMultiTileObjectModel::GetTypeInfo(void) const
// &m_typeInfo (returns base addr)
// FLAGS: -fno-schedule-insns

extern char ISimsMultiTileObjectModel__m_typeInfo[];

class ISimsMultiTileObjectModel {
public:
    char* GetTypeInfo() const;
};

char* ISimsMultiTileObjectModel::GetTypeInfo() const {
    return ISimsMultiTileObjectModel__m_typeInfo;
}
