// 0x80229C5C EIPointAmbLight::GetTypeKey (12B) const
extern int g_EIPointAmbLight_TypeKey[3];
struct EIPointAmbLight_GTK { int GetTypeKey() const; };
int EIPointAmbLight_GTK::GetTypeKey() const { return g_EIPointAmbLight_TypeKey[0]; }
