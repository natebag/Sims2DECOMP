// 0x803C142C EStorable::GetTypeName (12B) const
extern char* g_EStorable_TypeName[3];
struct EStorable_GTN { const char* GetTypeName() const; };
const char* EStorable_GTN::GetTypeName() const { return g_EStorable_TypeName[0]; }
