// 0x80364B48 EFontData::GetTypeName (12B) const
extern char* g_EFontData_TypeName[3];
struct EFontData_GTN { const char* GetTypeName() const; };
const char* EFontData_GTN::GetTypeName() const { return g_EFontData_TypeName[0]; }
