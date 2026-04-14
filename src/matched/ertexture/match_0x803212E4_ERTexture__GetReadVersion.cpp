// 0x803212E4 ERTexture::GetReadVersion (12B)
struct RVBlock_ERTexture { unsigned short ver[256]; };
extern RVBlock_ERTexture g_ERTexture_ReadVersion[3];
struct ERTexture_GRV { unsigned short GetReadVersion(); };
unsigned short ERTexture_GRV::GetReadVersion() { return g_ERTexture_ReadVersion[0].ver[0]; }
