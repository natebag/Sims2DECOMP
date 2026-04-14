// 0x80238130 ERLevel::GetReadVersion (12B)
struct RVBlock_ERLevel { unsigned short ver[256]; };
extern RVBlock_ERLevel g_ERLevel_ReadVersion[3];
struct ERLevel_GRV { unsigned short GetReadVersion(); };
unsigned short ERLevel_GRV::GetReadVersion() { return g_ERLevel_ReadVersion[0].ver[0]; }
