// 0x80364B3C EFontData::GetTypeInfo (12B) const
struct TypeInfo_EFontData { char data[256]; };
extern TypeInfo_EFontData g_EFontData_TypeInfo[3];
struct EFontData_GTI { TypeInfo_EFontData* GetTypeInfo() const; };
TypeInfo_EFontData* EFontData_GTI::GetTypeInfo() const { return &g_EFontData_TypeInfo[0]; }
