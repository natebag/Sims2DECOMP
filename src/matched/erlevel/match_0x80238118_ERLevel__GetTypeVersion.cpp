// 0x80238118 ERLevel::GetTypeVersion (12B) const
struct VerBlock_ERLevel { unsigned short ver[256]; };
extern VerBlock_ERLevel g_ERLevel_TypeVersion[3];
struct ERLevel_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERLevel_GTV::GetTypeVersion() const { return g_ERLevel_TypeVersion[0].ver[0]; }
