// 0x8022B830 EISpotLight::GetTypeKey (12B) const
extern int g_EISpotLight_TypeKey[3];
struct EISpotLight_GTK { int GetTypeKey() const; };
int EISpotLight_GTK::GetTypeKey() const { return g_EISpotLight_TypeKey[0]; }
