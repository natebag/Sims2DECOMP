// 0x80226F40 EIAmbLight::GetTypeVersion (12B) const
struct VerBlock_EIAmbLight { unsigned short ver[256]; };
extern VerBlock_EIAmbLight g_EIAmbLight_TypeVersion[3];
struct EIAmbLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIAmbLight_GTV::GetTypeVersion() const { return g_EIAmbLight_TypeVersion[0].ver[0]; }
