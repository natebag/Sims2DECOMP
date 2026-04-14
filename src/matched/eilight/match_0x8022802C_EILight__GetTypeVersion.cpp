// 0x8022802C EILight::GetTypeVersion (12B) const
struct VerBlock_EILight { unsigned short ver[256]; };
extern VerBlock_EILight g_EILight_TypeVersion[3];
struct EILight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EILight_GTV::GetTypeVersion() const { return g_EILight_TypeVersion[0].ver[0]; }
