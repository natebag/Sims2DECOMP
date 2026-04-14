// 0x80226F34 EIAmbLight::GetTypeKey (12B) const
extern int g_EIAmbLight_TypeKey[3];
struct EIAmbLight_GTK { int GetTypeKey() const; };
int EIAmbLight_GTK::GetTypeKey() const { return g_EIAmbLight_TypeKey[0]; }
