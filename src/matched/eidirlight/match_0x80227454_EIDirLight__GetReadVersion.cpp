// 0x80227454 EIDirLight::GetReadVersion (12B)
struct RVBlock_EIDirLight { unsigned short ver[256]; };
extern RVBlock_EIDirLight g_EIDirLight_ReadVersion[3];
struct EIDirLight_GRV { unsigned short GetReadVersion(); };
unsigned short EIDirLight_GRV::GetReadVersion() { return g_EIDirLight_ReadVersion[0].ver[0]; }
