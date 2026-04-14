// 0x8022B068 EIPortalPointLight::GetTypeInfoStatic (12B)
struct TypeInfo_EIPortalPointLight { char data[256]; };
extern TypeInfo_EIPortalPointLight g_EIPortalPointLight_TypeInfo[3];
TypeInfo_EIPortalPointLight* EIPortalPointLight_GetTypeInfoStatic() { return &g_EIPortalPointLight_TypeInfo[0]; }
