// 0x80317878 ERFont::GetTypeInfoStatic (12B)
struct TypeInfo_ERFont { char data[256]; };
extern TypeInfo_ERFont g_ERFont_TypeInfo[3];
TypeInfo_ERFont* ERFont_GetTypeInfoStatic() { return &g_ERFont_TypeInfo[0]; }
