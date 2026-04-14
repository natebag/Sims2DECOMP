// 0x80364724 EFontCharacter::GetTypeName (12B) const
extern char* g_EFontCharacter_TypeName[3];
struct EFontCharacter_GTN { const char* GetTypeName() const; };
const char* EFontCharacter_GTN::GetTypeName() const { return g_EFontCharacter_TypeName[0]; }
