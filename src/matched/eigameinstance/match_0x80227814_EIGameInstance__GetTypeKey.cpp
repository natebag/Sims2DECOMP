// 0x80227814 EIGameInstance::GetTypeKey (12B) const
extern int g_EIGameInstance_TypeKey[3];
struct EIGameInstance_GTK { int GetTypeKey() const; };
int EIGameInstance_GTK::GetTypeKey() const { return g_EIGameInstance_TypeKey[0]; }
