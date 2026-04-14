// 0x8022B074 EIPortalPointLight::GetReadVersion (12B)
struct RVBlock_EIPortalPointLight { unsigned short ver[256]; };
extern RVBlock_EIPortalPointLight g_EIPortalPointLight_ReadVersion[3];
struct EIPortalPointLight_GRV { unsigned short GetReadVersion(); };
unsigned short EIPortalPointLight_GRV::GetReadVersion() { return g_EIPortalPointLight_ReadVersion[0].ver[0]; }
