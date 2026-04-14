// 0x803212C0 ERTexture::GetTypeKey (12B) const
extern int g_ERTexture_TypeKey[3];
struct ERTexture_GTK { int GetTypeKey() const; };
int ERTexture_GTK::GetTypeKey() const { return g_ERTexture_TypeKey[0]; }
