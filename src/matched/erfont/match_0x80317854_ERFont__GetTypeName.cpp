// 0x80317854 ERFont::GetTypeName (12B) const
extern char* g_ERFont_TypeName[3];
struct ERFont_GTN { const char* GetTypeName() const; };
const char* ERFont_GTN::GetTypeName() const { return g_ERFont_TypeName[0]; }
