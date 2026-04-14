// 0x80317860 ERFont::GetTypeKey (12B) const
extern int g_ERFont_TypeKey[3];
struct ERFont_GTK { int GetTypeKey() const; };
int ERFont_GTK::GetTypeKey() const { return g_ERFont_TypeKey[0]; }
