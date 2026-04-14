// 0x80317884 ERFont::GetReadVersion (12B)
struct RVBlock_ERFont { unsigned short ver[256]; };
extern RVBlock_ERFont g_ERFont_ReadVersion[3];
struct ERFont_GRV { unsigned short GetReadVersion(); };
unsigned short ERFont_GRV::GetReadVersion() { return g_ERFont_ReadVersion[0].ver[0]; }
