// 0x80364B6C EFontData::GetTypeInfoStatic (12B)
struct TypeInfo_EFontData { char data[256]; };
extern TypeInfo_EFontData g_EFontData_TypeInfo[3];
TypeInfo_EFontData* EFontData_GetTypeInfoStatic() { return &g_EFontData_TypeInfo[0]; }
