// 0x8022B818 EISpotLight::GetTypeInfo (12B) const
struct TypeInfo_EISpotLight { char data[256]; };
extern TypeInfo_EISpotLight g_EISpotLight_TypeInfo[3];
struct EISpotLight_GTI { TypeInfo_EISpotLight* GetTypeInfo() const; };
TypeInfo_EISpotLight* EISpotLight_GTI::GetTypeInfo() const { return &g_EISpotLight_TypeInfo[0]; }
