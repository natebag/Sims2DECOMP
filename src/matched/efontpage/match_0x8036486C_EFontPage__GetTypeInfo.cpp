// 0x8036486C EFontPage::GetTypeInfo (12B) const
struct TypeInfo_EFontPage { char data[256]; };
extern TypeInfo_EFontPage g_EFontPage_TypeInfo[3];
struct EFontPage_GTI { TypeInfo_EFontPage* GetTypeInfo() const; };
TypeInfo_EFontPage* EFontPage_GTI::GetTypeInfo() const { return &g_EFontPage_TypeInfo[0]; }
