// 0x80054128 ISimsMultiTileObjectModel::GetReadVersion (12B)

struct RVBlock_ISimsMultiTileObjectModel { unsigned short ver[256]; };
extern RVBlock_ISimsMultiTileObjectModel g_ISimsMultiTileObjectModel_ReadVersion[3];

struct ISimsMultiTileObjectModel_GRV {
    unsigned short GetReadVersion();
};

unsigned short ISimsMultiTileObjectModel_GRV::GetReadVersion() {
    return g_ISimsMultiTileObjectModel_ReadVersion[0].ver[0];
}
