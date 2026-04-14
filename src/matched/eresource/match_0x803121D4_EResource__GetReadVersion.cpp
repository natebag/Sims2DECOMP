// 0x803121D4 EResource::GetReadVersion (12B)
struct RVBlock_EResource { unsigned short ver[256]; };
extern RVBlock_EResource g_EResource_ReadVersion[3];
struct EResource_GRV { unsigned short GetReadVersion(); };
unsigned short EResource_GRV::GetReadVersion() { return g_EResource_ReadVersion[0].ver[0]; }
