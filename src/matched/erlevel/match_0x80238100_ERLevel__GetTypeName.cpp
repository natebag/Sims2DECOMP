// 0x80238100 ERLevel::GetTypeName (12B) const
extern char* g_ERLevel_TypeName[3];
struct ERLevel_GTN { const char* GetTypeName() const; };
const char* ERLevel_GTN::GetTypeName() const { return g_ERLevel_TypeName[0]; }
