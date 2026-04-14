// 0x80364878 EFontPage::GetTypeName (12B) const
extern char* g_EFontPage_TypeName[3];
struct EFontPage_GTN { const char* GetTypeName() const; };
const char* EFontPage_GTN::GetTypeName() const { return g_EFontPage_TypeName[0]; }
