// 0x80364A10 EFontSize::GetReadVersion (12B)
struct RVBlock_EFontSize { unsigned short ver[256]; };
extern RVBlock_EFontSize g_EFontSize_ReadVersion[3];
struct EFontSize_GRV { unsigned short GetReadVersion(); };
unsigned short EFontSize_GRV::GetReadVersion() { return g_EFontSize_ReadVersion[0].ver[0]; }
