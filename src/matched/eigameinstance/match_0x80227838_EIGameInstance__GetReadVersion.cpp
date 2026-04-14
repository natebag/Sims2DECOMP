// 0x80227838 EIGameInstance::GetReadVersion (12B)
struct RVBlock_EIGameInstance { unsigned short ver[256]; };
extern RVBlock_EIGameInstance g_EIGameInstance_ReadVersion[3];
struct EIGameInstance_GRV { unsigned short GetReadVersion(); };
unsigned short EIGameInstance_GRV::GetReadVersion() { return g_EIGameInstance_ReadVersion[0].ver[0]; }
