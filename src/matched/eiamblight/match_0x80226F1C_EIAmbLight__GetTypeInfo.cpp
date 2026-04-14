// 0x80226F1C EIAmbLight::GetTypeInfo (12B) const
struct TypeInfo_EIAmbLight { char data[256]; };
extern TypeInfo_EIAmbLight g_EIAmbLight_TypeInfo[3];
struct EIAmbLight_GTI { TypeInfo_EIAmbLight* GetTypeInfo() const; };
TypeInfo_EIAmbLight* EIAmbLight_GTI::GetTypeInfo() const { return &g_EIAmbLight_TypeInfo[0]; }
