// 0x8022A590 EIPointLight::GetTypeInfoStatic(void) (12B)
struct TypeInfo_EIPL { char data[256]; };
extern TypeInfo_EIPL g_EIPL_TypeInfo[3];
TypeInfo_EIPL* EIPointLight_GetTypeInfoStatic() { return &g_EIPL_TypeInfo[0]; }
