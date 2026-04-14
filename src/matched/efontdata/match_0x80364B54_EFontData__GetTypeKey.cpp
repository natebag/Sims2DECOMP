// 0x80364B54 EFontData::GetTypeKey (12B) const
extern int g_EFontData_TypeKey[3];
struct EFontData_GTK { int GetTypeKey() const; };
int EFontData_GTK::GetTypeKey() const { return g_EFontData_TypeKey[0]; }
