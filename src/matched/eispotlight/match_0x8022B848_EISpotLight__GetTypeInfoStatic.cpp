// 0x8022B848 EISpotLight::GetTypeInfoStatic (12B)
struct TypeInfo_EISpotLight { char data[256]; };
extern TypeInfo_EISpotLight g_EISpotLight_TypeInfo[3];
TypeInfo_EISpotLight* EISpotLight_GetTypeInfoStatic() { return &g_EISpotLight_TypeInfo[0]; }
