// 0x803C1444 EStorable::GetTypeVersion (12B) const
struct VerBlock_EStorable { unsigned short ver[256]; };
extern VerBlock_EStorable g_EStorable_TypeVersion[3];
struct EStorable_GTV { unsigned short GetTypeVersion() const; };
unsigned short EStorable_GTV::GetTypeVersion() const { return g_EStorable_TypeVersion[0].ver[0]; }
