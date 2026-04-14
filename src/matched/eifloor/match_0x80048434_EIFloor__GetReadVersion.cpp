// 0x80048434 EIFloor::GetReadVersion (12B)
struct RVBlock_EIFloor { unsigned short ver[256]; };
extern RVBlock_EIFloor g_EIFloor_ReadVersion[3];
struct EIFloor_GRV { unsigned short GetReadVersion(); };
unsigned short EIFloor_GRV::GetReadVersion() { return g_EIFloor_ReadVersion[0].ver[0]; }
