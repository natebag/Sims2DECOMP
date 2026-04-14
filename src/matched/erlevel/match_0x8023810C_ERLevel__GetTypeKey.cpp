// 0x8023810C ERLevel::GetTypeKey (12B) const
extern int g_ERLevel_TypeKey[3];
struct ERLevel_GTK { int GetTypeKey() const; };
int ERLevel_GTK::GetTypeKey() const { return g_ERLevel_TypeKey[0]; }
