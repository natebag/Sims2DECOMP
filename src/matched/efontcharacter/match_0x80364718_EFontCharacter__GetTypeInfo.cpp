// 0x80364718 EFontCharacter::GetTypeInfo (12B) const
struct TypeInfo_EFontCharacter { char data[256]; };
extern TypeInfo_EFontCharacter g_EFontCharacter_TypeInfo[3];
struct EFontCharacter_GTI { TypeInfo_EFontCharacter* GetTypeInfo() const; };
TypeInfo_EFontCharacter* EFontCharacter_GTI::GetTypeInfo() const { return &g_EFontCharacter_TypeInfo[0]; }
