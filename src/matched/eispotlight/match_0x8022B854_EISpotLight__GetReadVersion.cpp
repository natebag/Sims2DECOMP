// 0x8022B854 EISpotLight::GetReadVersion (12B)
struct RVBlock_EISpotLight { unsigned short ver[256]; };
extern RVBlock_EISpotLight g_EISpotLight_ReadVersion[3];
struct EISpotLight_GRV { unsigned short GetReadVersion(); };
unsigned short EISpotLight_GRV::GetReadVersion() { return g_EISpotLight_ReadVersion[0].ver[0]; }
