// 0x8005411C ISimsMultiTileObjectModel::GetTypeInfoStatic (12B)

struct TypeInfo_ISimsMultiTileObjectModel { char data[256]; };
extern TypeInfo_ISimsMultiTileObjectModel g_ISimsMultiTileObjectModel_TypeInfo[3];

TypeInfo_ISimsMultiTileObjectModel* ISimsMultiTileObjectModel_GetTypeInfoStatic() {
    return &g_ISimsMultiTileObjectModel_TypeInfo[0];
}
