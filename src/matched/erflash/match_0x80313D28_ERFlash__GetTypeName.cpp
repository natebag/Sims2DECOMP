// 0x80313D28 ERFlash::GetTypeName (12B) const
extern char* g_ERFlash_TypeName[3];
struct ERFlash_GTN { const char* GetTypeName() const; };
const char* ERFlash_GTN::GetTypeName() const { return g_ERFlash_TypeName[0]; }
