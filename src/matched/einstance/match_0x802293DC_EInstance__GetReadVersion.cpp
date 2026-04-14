// 0x802293DC EInstance::GetReadVersion (12B)
struct RVBlock_EInstance { unsigned short ver[256]; };
extern RVBlock_EInstance g_EInstance_ReadVersion[3];
struct EInstance_GRV { unsigned short GetReadVersion(); };
unsigned short EInstance_GRV::GetReadVersion() { return g_EInstance_ReadVersion[0].ver[0]; }
