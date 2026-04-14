// 0x803121A4 EResource::GetTypeName (12B) const
extern char* g_EResource_TypeName[3];
struct EResource_GTN { const char* GetTypeName() const; };
const char* EResource_GTN::GetTypeName() const { return g_EResource_TypeName[0]; }
