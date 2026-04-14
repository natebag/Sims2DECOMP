// 0x8036489C EFontPage::GetTypeInfoStatic (12B)
struct TypeInfo_EFontPage { char data[256]; };
extern TypeInfo_EFontPage g_EFontPage_TypeInfo[3];
TypeInfo_EFontPage* EFontPage_GetTypeInfoStatic() { return &g_EFontPage_TypeInfo[0]; }
