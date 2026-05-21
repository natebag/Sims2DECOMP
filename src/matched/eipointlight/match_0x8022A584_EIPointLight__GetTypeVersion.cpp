// 0x8022A584 EIPointLight::GetTypeVersion(void) const (12B)
struct VerBlock_EIPL { unsigned short ver[256]; };
extern VerBlock_EIPL g_EIPointLight_TypeVersion[3];
struct EIPL_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIPL_GTV::GetTypeVersion() const { return g_EIPointLight_TypeVersion[0].ver[0]; }
