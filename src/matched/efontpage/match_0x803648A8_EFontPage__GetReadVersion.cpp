// 0x803648A8 EFontPage::GetReadVersion (12B)
struct RVBlock_EFontPage { unsigned short ver[256]; };
extern RVBlock_EFontPage g_EFontPage_ReadVersion[3];
struct EFontPage_GRV { unsigned short GetReadVersion(); };
unsigned short EFontPage_GRV::GetReadVersion() { return g_EFontPage_ReadVersion[0].ver[0]; }
