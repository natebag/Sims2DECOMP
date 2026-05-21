// 0x80226F28 EIAmbLight::GetTypeName(void) const (12B)
extern char* g_EIAmbLight_TypeName[3];
struct EIAmbLight_GTN { const char* GetTypeName() const; };
const char* EIAmbLight_GTN::GetTypeName() const { return g_EIAmbLight_TypeName[0]; }
