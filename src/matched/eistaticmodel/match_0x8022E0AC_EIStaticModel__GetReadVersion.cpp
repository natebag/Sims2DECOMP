// 0x8022E0AC EIStaticModel::GetReadVersion (12B)
struct RVBlock_EIStaticModel { unsigned short ver[256]; };
extern RVBlock_EIStaticModel g_EIStaticModel_ReadVersion[3];
struct EIStaticModel_GRV { unsigned short GetReadVersion(); };
unsigned short EIStaticModel_GRV::GetReadVersion() { return g_EIStaticModel_ReadVersion[0].ver[0]; }
