// 0x800540F8 ISimsMultiTileObjectModel::GetTypeName (12B) const

extern char* g_ISimsMultiTileObjectModel_TypeName[3];

struct ISimsMultiTileObjectModel_GTN {
    const char* GetTypeName() const;
};

const char* ISimsMultiTileObjectModel_GTN::GetTypeName() const {
    return g_ISimsMultiTileObjectModel_TypeName[0];
}
