// 0x80313D40 ERFlash::GetTypeVersion (12B) const
struct VerBlock_ERFlash { unsigned short ver[256]; };
extern VerBlock_ERFlash g_ERFlash_TypeVersion[3];
struct ERFlash_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERFlash_GTV::GetTypeVersion() const { return g_ERFlash_TypeVersion[0].ver[0]; }
