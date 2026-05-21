// 0x8022A578 EIPointLight::GetTypeKey(void) const (12B)
extern int g_EIPointLight_TypeKey[3];
struct EIPointLight_GTK { int GetTypeKey() const; };
int EIPointLight_GTK::GetTypeKey() const { return g_EIPointLight_TypeKey[0]; }
