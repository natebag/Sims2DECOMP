// 0x800540EC ISimsMultiTileObjectModel::GetTypeInfo (12B) const

struct TypeInfo_ISimsMultiTileObjectModel { char data[256]; };
extern TypeInfo_ISimsMultiTileObjectModel g_ISimsMultiTileObjectModel_TypeInfo[3];

struct ISimsMultiTileObjectModel_GTI {
    TypeInfo_ISimsMultiTileObjectModel* GetTypeInfo() const;
};

TypeInfo_ISimsMultiTileObjectModel* ISimsMultiTileObjectModel_GTI::GetTypeInfo() const {
    return &g_ISimsMultiTileObjectModel_TypeInfo[0];
}
