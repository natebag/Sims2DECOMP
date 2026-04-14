// 0x8022B05C EIPortalPointLight::GetTypeVersion (12B) const
struct VerBlock_EIPortalPointLight { unsigned short ver[256]; };
extern VerBlock_EIPortalPointLight g_EIPortalPointLight_TypeVersion[3];
struct EIPortalPointLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIPortalPointLight_GTV::GetTypeVersion() const { return g_EIPortalPointLight_TypeVersion[0].ver[0]; }
