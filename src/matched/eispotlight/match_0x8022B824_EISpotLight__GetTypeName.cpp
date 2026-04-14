// 0x8022B824 EISpotLight::GetTypeName (12B) const
extern char* g_EISpotLight_TypeName[3];
struct EISpotLight_GTN { const char* GetTypeName() const; };
const char* EISpotLight_GTN::GetTypeName() const { return g_EISpotLight_TypeName[0]; }
