// 0x8022A59C EIPointLight::GetReadVersion (12B)
struct RVBlock_EIPointLight { unsigned short ver[256]; };
extern RVBlock_EIPointLight g_EIPointLight_ReadVersion[3];
struct EIPointLight_GRV { unsigned short GetReadVersion(); };
unsigned short EIPointLight_GRV::GetReadVersion() { return g_EIPointLight_ReadVersion[0].ver[0]; }
