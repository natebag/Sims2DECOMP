// 0x8022B83C EISpotLight::GetTypeVersion (12B) const
struct VerBlock_EISpotLight { unsigned short ver[256]; };
extern VerBlock_EISpotLight g_EISpotLight_TypeVersion[3];
struct EISpotLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EISpotLight_GTV::GetTypeVersion() const { return g_EISpotLight_TypeVersion[0].ver[0]; }
