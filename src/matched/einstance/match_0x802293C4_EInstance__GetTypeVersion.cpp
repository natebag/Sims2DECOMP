// 0x802293C4 EInstance::GetTypeVersion (12B) const
struct VerBlock_EInstance { unsigned short ver[256]; };
extern VerBlock_EInstance g_EInstance_TypeVersion[3];
struct EInstance_GTV { unsigned short GetTypeVersion() const; };
unsigned short EInstance_GTV::GetTypeVersion() const { return g_EInstance_TypeVersion[0].ver[0]; }
