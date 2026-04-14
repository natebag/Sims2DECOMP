// 0x80364730 EFontCharacter::GetTypeKey (12B) const
extern int g_EFontCharacter_TypeKey[3];
struct EFontCharacter_GTK { int GetTypeKey() const; };
int EFontCharacter_GTK::GetTypeKey() const { return g_EFontCharacter_TypeKey[0]; }
