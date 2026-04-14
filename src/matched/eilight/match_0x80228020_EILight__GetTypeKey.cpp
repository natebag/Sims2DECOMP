// 0x80228020 EILight::GetTypeKey (12B) const
extern int g_EILight_TypeKey[3];
struct EILight_GTK { int GetTypeKey() const; };
int EILight_GTK::GetTypeKey() const { return g_EILight_TypeKey[0]; }
