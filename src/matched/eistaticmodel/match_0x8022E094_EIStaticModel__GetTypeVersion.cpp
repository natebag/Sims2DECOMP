// 0x8022E094 EIStaticModel::GetTypeVersion (12B) const
struct VerBlock_EIStaticModel { unsigned short ver[256]; };
extern VerBlock_EIStaticModel g_EIStaticModel_TypeVersion[3];
struct EIStaticModel_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIStaticModel_GTV::GetTypeVersion() const { return g_EIStaticModel_TypeVersion[0].ver[0]; }
