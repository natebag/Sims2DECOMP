// 0x8036473C EFontCharacter::GetTypeVersion (12B) const
struct VerBlock_EFontCharacter { unsigned short ver[256]; };
extern VerBlock_EFontCharacter g_EFontCharacter_TypeVersion[3];
struct EFontCharacter_GTV { unsigned short GetTypeVersion() const; };
unsigned short EFontCharacter_GTV::GetTypeVersion() const { return g_EFontCharacter_TypeVersion[0].ver[0]; }
