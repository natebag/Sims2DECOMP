// 0x8022B044 EIPortalPointLight::GetTypeName(void) const (12B)
extern char* g_EIPPL_TypeName[3];
struct EIPPL_GTN { const char* GetTypeName() const; };
const char* EIPPL_GTN::GetTypeName() const { return g_EIPPL_TypeName[0]; }
