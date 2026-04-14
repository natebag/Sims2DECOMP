// 0x80364B78 EFontData::GetReadVersion (12B)
struct RVBlock_EFontData { unsigned short ver[256]; };
extern RVBlock_EFontData g_EFontData_ReadVersion[3];
struct EFontData_GRV { unsigned short GetReadVersion(); };
unsigned short EFontData_GRV::GetReadVersion() { return g_EFontData_ReadVersion[0].ver[0]; }
