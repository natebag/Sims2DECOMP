// 0x80364748 EFontCharacter::GetTypeInfoStatic (12B)
struct TypeInfo_EFontCharacter { char data[256]; };
extern TypeInfo_EFontCharacter g_EFontCharacter_TypeInfo[3];
TypeInfo_EFontCharacter* EFontCharacter_GetTypeInfoStatic() { return &g_EFontCharacter_TypeInfo[0]; }
