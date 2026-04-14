// 0x803121BC EResource::GetTypeVersion (12B) const
struct VerBlock_EResource { unsigned short ver[256]; };
extern VerBlock_EResource g_EResource_TypeVersion[3];
struct EResource_GTV { unsigned short GetTypeVersion() const; };
unsigned short EResource_GTV::GetTypeVersion() const { return g_EResource_TypeVersion[0].ver[0]; }
