// 0x8031B2E0 ERModel::GetReadVersion (12B)
struct RVBlock_ERModel { unsigned short ver[256]; };
extern RVBlock_ERModel g_ERModel_ReadVersion[3];
struct ERModel_GRV { unsigned short GetReadVersion(); };
unsigned short ERModel_GRV::GetReadVersion() { return g_ERModel_ReadVersion[0].ver[0]; }
