// 0x80229C80 EIPointAmbLight::GetReadVersion (12B)
struct RVBlock_EIPointAmbLight { unsigned short ver[256]; };
extern RVBlock_EIPointAmbLight g_EIPointAmbLight_ReadVersion[3];
struct EIPointAmbLight_GRV { unsigned short GetReadVersion(); };
unsigned short EIPointAmbLight_GRV::GetReadVersion() { return g_EIPointAmbLight_ReadVersion[0].ver[0]; }
