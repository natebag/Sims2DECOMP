// 0x80226F34 EIAmbLight::GetTypeKey(void) const (12B)
extern int g_EIAmbLight_TypeKey[3];
struct EIAmbLight_GTK { int GetTypeKey() const; };
int EIAmbLight_GTK::GetTypeKey() const { return g_EIAmbLight_TypeKey[0]; }
