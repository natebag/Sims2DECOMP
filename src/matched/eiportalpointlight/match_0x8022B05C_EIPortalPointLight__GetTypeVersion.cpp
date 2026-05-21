// 0x8022B05C EIPortalPointLight::GetTypeVersion(void) const (12B)
struct VerBlock_EIPPL { unsigned short ver[256]; };
extern VerBlock_EIPPL g_EIPPL_TypeVersion[3];
struct EIPPL_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIPPL_GTV::GetTypeVersion() const { return g_EIPPL_TypeVersion[0].ver[0]; }
