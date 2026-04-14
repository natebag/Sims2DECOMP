// 0x80313D58 ERFlash::GetReadVersion (12B)
struct RVBlock_ERFlash { unsigned short ver[256]; };
extern RVBlock_ERFlash g_ERFlash_ReadVersion[3];
struct ERFlash_GRV { unsigned short GetReadVersion(); };
unsigned short ERFlash_GRV::GetReadVersion() { return g_ERFlash_ReadVersion[0].ver[0]; }
