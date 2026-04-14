// 0x803649EC EFontSize::GetTypeKey (12B) const
extern int g_EFontSize_TypeKey[3];
struct EFontSize_GTK { int GetTypeKey() const; };
int EFontSize_GTK::GetTypeKey() const { return g_EFontSize_TypeKey[0]; }
