// 0x8022A56C EIPointLight::GetTypeName(void) const (12B)
extern char* g_EIPointLight_TypeName[3];
struct EIPointLight_GTN { const char* GetTypeName() const; };
const char* EIPointLight_GTN::GetTypeName() const { return g_EIPointLight_TypeName[0]; }
