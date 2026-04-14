// 0x8022743C EIDirLight::GetTypeVersion (12B) const
struct VerBlock_EIDirLight { unsigned short ver[256]; };
extern VerBlock_EIDirLight g_EIDirLight_TypeVersion[3];
struct EIDirLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIDirLight_GTV::GetTypeVersion() const { return g_EIDirLight_TypeVersion[0].ver[0]; }
