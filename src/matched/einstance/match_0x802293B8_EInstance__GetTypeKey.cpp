// 0x802293B8 EInstance::GetTypeKey (12B) const
extern int g_EInstance_TypeKey[3];
struct EInstance_GTK { int GetTypeKey() const; };
int EInstance_GTK::GetTypeKey() const { return g_EInstance_TypeKey[0]; }
