// 0x80364884 EFontPage::GetTypeKey (12B) const
extern int g_EFontPage_TypeKey[3];
struct EFontPage_GTK { int GetTypeKey() const; };
int EFontPage_GTK::GetTypeKey() const { return g_EFontPage_TypeKey[0]; }
