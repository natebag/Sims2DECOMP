// 0x8031786C ERFont::GetTypeVersion (12B) const
struct VerBlock_ERFont { unsigned short ver[256]; };
extern VerBlock_ERFont g_ERFont_TypeVersion[3];
struct ERFont_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERFont_GTV::GetTypeVersion() const { return g_ERFont_TypeVersion[0].ver[0]; }
