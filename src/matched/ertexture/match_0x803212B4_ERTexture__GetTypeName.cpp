// 0x803212B4 ERTexture::GetTypeName (12B) const
extern char* g_ERTexture_TypeName[3];
struct ERTexture_GTN { const char* GetTypeName() const; };
const char* ERTexture_GTN::GetTypeName() const { return g_ERTexture_TypeName[0]; }
