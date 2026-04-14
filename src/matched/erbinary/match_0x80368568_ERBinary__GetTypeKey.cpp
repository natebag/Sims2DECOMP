// 0x80368568 ERBinary::GetTypeKey (12B) const
extern int g_ERBinary_TypeKey[3];
struct ERBinary_GTK { int GetTypeKey() const; };
int ERBinary_GTK::GetTypeKey() const { return g_ERBinary_TypeKey[0]; }
