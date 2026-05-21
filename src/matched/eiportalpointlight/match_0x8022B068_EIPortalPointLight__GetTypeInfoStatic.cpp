// 0x8022B068 EIPortalPointLight::GetTypeInfoStatic(void) (12B)
struct TypeInfo_EIPPL { char data[256]; };
extern TypeInfo_EIPPL g_EIPPL_TypeInfo[3];
TypeInfo_EIPPL* EIPPL_GetTypeInfoStatic() { return &g_EIPPL_TypeInfo[0]; }
