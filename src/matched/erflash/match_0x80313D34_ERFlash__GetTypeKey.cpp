// 0x80313D34 ERFlash::GetTypeKey (12B) const
extern int g_ERFlash_TypeKey[3];
struct ERFlash_GTK { int GetTypeKey() const; };
int ERFlash_GTK::GetTypeKey() const { return g_ERFlash_TypeKey[0]; }
