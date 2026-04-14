// 0x803649D4 EFontSize::GetTypeInfo (12B) const
struct TypeInfo_EFontSize { char data[256]; };
extern TypeInfo_EFontSize g_EFontSize_TypeInfo[3];
struct EFontSize_GTI { TypeInfo_EFontSize* GetTypeInfo() const; };
TypeInfo_EFontSize* EFontSize_GTI::GetTypeInfo() const { return &g_EFontSize_TypeInfo[0]; }
