// 0x80364A04 EFontSize::GetTypeInfoStatic (12B)
struct TypeInfo_EFontSize { char data[256]; };
extern TypeInfo_EFontSize g_EFontSize_TypeInfo[3];
TypeInfo_EFontSize* EFontSize_GetTypeInfoStatic() { return &g_EFontSize_TypeInfo[0]; }
