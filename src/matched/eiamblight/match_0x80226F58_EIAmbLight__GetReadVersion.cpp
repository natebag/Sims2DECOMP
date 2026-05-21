// 0x80226F58 EIAmbLight::GetReadVersion(void) (12B)
struct RVBlock_EIAmbLight { unsigned short ver[256]; };
extern RVBlock_EIAmbLight g_EIAmbLight_ReadVersion[3];
struct EIAmbLight_GRV { unsigned short GetReadVersion(); };
unsigned short EIAmbLight_GRV::GetReadVersion() { return g_EIAmbLight_ReadVersion[0].ver[0]; }
