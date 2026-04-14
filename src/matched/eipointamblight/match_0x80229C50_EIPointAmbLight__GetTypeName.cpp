// 0x80229C50 EIPointAmbLight::GetTypeName (12B) const
extern char* g_EIPointAmbLight_TypeName[3];
struct EIPointAmbLight_GTN { const char* GetTypeName() const; };
const char* EIPointAmbLight_GTN::GetTypeName() const { return g_EIPointAmbLight_TypeName[0]; }
