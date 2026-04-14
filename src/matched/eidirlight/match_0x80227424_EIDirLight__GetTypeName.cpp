// 0x80227424 EIDirLight::GetTypeName (12B) const
extern char* g_EIDirLight_TypeName[3];
struct EIDirLight_GTN { const char* GetTypeName() const; };
const char* EIDirLight_GTN::GetTypeName() const { return g_EIDirLight_TypeName[0]; }
