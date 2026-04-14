// 0x803649E0 EFontSize::GetTypeName (12B) const
extern char* g_EFontSize_TypeName[3];
struct EFontSize_GTN { const char* GetTypeName() const; };
const char* EFontSize_GTN::GetTypeName() const { return g_EFontSize_TypeName[0]; }
