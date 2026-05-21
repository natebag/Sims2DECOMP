// 0x8022B050 EIPortalPointLight::GetTypeKey(void) const (12B)
extern int g_EIPPL_TypeKey[3];
struct EIPPL_GTK { int GetTypeKey() const; };
int EIPPL_GTK::GetTypeKey() const { return g_EIPPL_TypeKey[0]; }
