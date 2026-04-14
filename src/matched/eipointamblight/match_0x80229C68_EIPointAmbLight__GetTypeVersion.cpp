// 0x80229C68 EIPointAmbLight::GetTypeVersion (12B) const
struct VerBlock_EIPointAmbLight { unsigned short ver[256]; };
extern VerBlock_EIPointAmbLight g_EIPointAmbLight_TypeVersion[3];
struct EIPointAmbLight_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIPointAmbLight_GTV::GetTypeVersion() const { return g_EIPointAmbLight_TypeVersion[0].ver[0]; }
