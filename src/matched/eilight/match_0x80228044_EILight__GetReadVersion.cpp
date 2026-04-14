// 0x80228044 EILight::GetReadVersion (12B)
struct RVBlock_EILight { unsigned short ver[256]; };
extern RVBlock_EILight g_EILight_ReadVersion[3];
struct EILight_GRV { unsigned short GetReadVersion(); };
unsigned short EILight_GRV::GetReadVersion() { return g_EILight_ReadVersion[0].ver[0]; }
