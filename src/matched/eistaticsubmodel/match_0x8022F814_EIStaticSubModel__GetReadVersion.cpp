// 0x8022F814 EIStaticSubModel::GetReadVersion (12B)
struct RVBlock_EIStaticSubModel { unsigned short ver[256]; };
extern RVBlock_EIStaticSubModel g_EIStaticSubModel_ReadVersion[3];
struct EIStaticSubModel_GRV { unsigned short GetReadVersion(); };
unsigned short EIStaticSubModel_GRV::GetReadVersion() { return g_EIStaticSubModel_ReadVersion[0].ver[0]; }
