// 0x802293AC EInstance::GetTypeName (12B) const
extern char* g_EInstance_TypeName[3];
struct EInstance_GTN { const char* GetTypeName() const; };
const char* EInstance_GTN::GetTypeName() const { return g_EInstance_TypeName[0]; }
