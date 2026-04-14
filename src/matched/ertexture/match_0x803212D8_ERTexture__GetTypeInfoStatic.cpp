// 0x803212D8 ERTexture::GetTypeInfoStatic (12B)
struct TypeInfo_ERTexture { char data[256]; };
extern TypeInfo_ERTexture g_ERTexture_TypeInfo[3];
TypeInfo_ERTexture* ERTexture_GetTypeInfoStatic() { return &g_ERTexture_TypeInfo[0]; }
