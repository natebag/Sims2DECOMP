// 0x8022B044 EIPortalPointLight::GetTypeName (12B) const
extern char* g_EIPortalPointLight_TypeName[3];
struct EIPortalPointLight_GTN { const char* GetTypeName() const; };
const char* EIPortalPointLight_GTN::GetTypeName() const { return g_EIPortalPointLight_TypeName[0]; }
