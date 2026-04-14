// 0x80313D4C ERFlash::GetTypeInfoStatic (12B)
struct TypeInfo_ERFlash { char data[256]; };
extern TypeInfo_ERFlash g_ERFlash_TypeInfo[3];
TypeInfo_ERFlash* ERFlash_GetTypeInfoStatic() { return &g_ERFlash_TypeInfo[0]; }
