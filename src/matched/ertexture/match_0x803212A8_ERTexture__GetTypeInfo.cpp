// 0x803212A8 ERTexture::GetTypeInfo (12B) const
struct TypeInfo_ERTexture { char data[256]; };
extern TypeInfo_ERTexture g_ERTexture_TypeInfo[3];
struct ERTexture_GTI { TypeInfo_ERTexture* GetTypeInfo() const; };
TypeInfo_ERTexture* ERTexture_GTI::GetTypeInfo() const { return &g_ERTexture_TypeInfo[0]; }
