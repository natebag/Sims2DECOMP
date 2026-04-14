// 0x803212CC ERTexture::GetTypeVersion (12B) const
struct VerBlock_ERTexture { unsigned short ver[256]; };
extern VerBlock_ERTexture g_ERTexture_TypeVersion[3];
struct ERTexture_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERTexture_GTV::GetTypeVersion() const { return g_ERTexture_TypeVersion[0].ver[0]; }
