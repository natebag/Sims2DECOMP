// 0x8031B2C8 ERModel::GetTypeVersion (12B) const
struct VerBlock_ERModel { unsigned short ver[256]; };
extern VerBlock_ERModel g_ERModel_TypeVersion[3];
struct ERModel_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERModel_GTV::GetTypeVersion() const { return g_ERModel_TypeVersion[0].ver[0]; }
