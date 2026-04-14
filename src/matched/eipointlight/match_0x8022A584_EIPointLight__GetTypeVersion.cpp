// 0x8022A584 EIPointLight::GetTypeVersion (12B) const
struct VerBlock_EIPointLight { unsigned short ver[256]; };
extern VerBlock_EIPointLight g_EIPointLight_TypeVersion[3];
struct EIPointLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIPointLight_GTV::GetTypeVersion() const { return g_EIPointLight_TypeVersion[0].ver[0]; }
