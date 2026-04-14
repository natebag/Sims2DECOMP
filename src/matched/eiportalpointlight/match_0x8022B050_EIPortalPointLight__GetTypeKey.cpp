// 0x8022B050 EIPortalPointLight::GetTypeKey (12B) const
extern int g_EIPortalPointLight_TypeKey[3];
struct EIPortalPointLight_GTK { int GetTypeKey() const; };
int EIPortalPointLight_GTK::GetTypeKey() const { return g_EIPortalPointLight_TypeKey[0]; }
