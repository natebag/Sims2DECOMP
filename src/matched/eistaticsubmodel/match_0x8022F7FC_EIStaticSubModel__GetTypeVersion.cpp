// 0x8022F7FC EIStaticSubModel::GetTypeVersion (12B) const
struct VerBlock_EIStaticSubModel { unsigned short ver[256]; };
extern VerBlock_EIStaticSubModel g_EIStaticSubModel_TypeVersion[3];
struct EIStaticSubModel_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIStaticSubModel_GTV::GetTypeVersion() const { return g_EIStaticSubModel_TypeVersion[0].ver[0]; }
