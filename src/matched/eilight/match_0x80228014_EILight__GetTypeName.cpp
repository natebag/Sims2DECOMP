// 0x80228014 EILight::GetTypeName (12B) const
extern char* g_EILight_TypeName[3];
struct EILight_GTN { const char* GetTypeName() const; };
const char* EILight_GTN::GetTypeName() const { return g_EILight_TypeName[0]; }
