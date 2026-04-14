// 0x80053F94 ISimsWallObjectModel::GetReadVersion (12B)
struct RVBlock_ISimsWallObjectModel { unsigned short ver[256]; };
extern RVBlock_ISimsWallObjectModel g_ISimsWallObjectModel_ReadVersion[3];
struct ISimsWallObjectModel_GRV { unsigned short GetReadVersion(); };
unsigned short ISimsWallObjectModel_GRV::GetReadVersion() { return g_ISimsWallObjectModel_ReadVersion[0].ver[0]; }
