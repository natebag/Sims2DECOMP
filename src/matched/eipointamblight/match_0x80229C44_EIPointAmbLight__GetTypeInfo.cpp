// 0x80229C44 EIPointAmbLight::GetTypeInfo (12B) const
struct TypeInfo_EIPointAmbLight { char data[256]; };
extern TypeInfo_EIPointAmbLight g_EIPointAmbLight_TypeInfo[3];
struct EIPointAmbLight_GTI { TypeInfo_EIPointAmbLight* GetTypeInfo() const; };
TypeInfo_EIPointAmbLight* EIPointAmbLight_GTI::GetTypeInfo() const { return &g_EIPointAmbLight_TypeInfo[0]; }
