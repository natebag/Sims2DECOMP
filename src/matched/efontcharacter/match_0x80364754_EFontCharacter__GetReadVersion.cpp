// 0x80364754 EFontCharacter::GetReadVersion (12B)
struct RVBlock_EFontCharacter { unsigned short ver[256]; };
extern RVBlock_EFontCharacter g_EFontCharacter_ReadVersion[3];
struct EFontCharacter_GRV { unsigned short GetReadVersion(); };
unsigned short EFontCharacter_GRV::GetReadVersion() { return g_EFontCharacter_ReadVersion[0].ver[0]; }
