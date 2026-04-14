// 0x8036855C ERBinary::GetTypeName (12B) const
extern char* g_ERBinary_TypeName[3];
struct ERBinary_GTN { const char* GetTypeName() const; };
const char* ERBinary_GTN::GetTypeName() const { return g_ERBinary_TypeName[0]; }
