// 0x803121B0 EResource::GetTypeKey (12B) const
extern int g_EResource_TypeKey[3];
struct EResource_GTK { int GetTypeKey() const; };
int EResource_GTK::GetTypeKey() const { return g_EResource_TypeKey[0]; }
