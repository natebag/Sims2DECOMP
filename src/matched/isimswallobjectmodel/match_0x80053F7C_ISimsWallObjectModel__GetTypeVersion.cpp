// 0x80053F7C ISimsWallObjectModel::GetTypeVersion (12B) const
struct VerBlock_ISimsWallObjectModel { unsigned short ver[256]; };
extern VerBlock_ISimsWallObjectModel g_ISimsWallObjectModel_TypeVersion[3];
struct ISimsWallObjectModel_GTV { unsigned short GetTypeVersion() const; };
unsigned short ISimsWallObjectModel_GTV::GetTypeVersion() const { return g_ISimsWallObjectModel_TypeVersion[0].ver[0]; }
