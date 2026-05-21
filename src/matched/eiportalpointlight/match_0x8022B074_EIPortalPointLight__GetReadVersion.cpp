// 0x8022B074 EIPortalPointLight::GetReadVersion(void) (12B)
struct RVBlock_EIPPL { unsigned short ver[256]; };
extern RVBlock_EIPPL g_EIPPL_ReadVersion[3];
struct EIPPL_GRV { unsigned short GetReadVersion(); };
unsigned short EIPPL_GRV::GetReadVersion() { return g_EIPPL_ReadVersion[0].ver[0]; }
