// 0x8022A590 EIPointLight::GetTypeInfoStatic (12B)
struct TypeInfo_EIPointLight { char data[256]; };
extern TypeInfo_EIPointLight g_EIPointLight_TypeInfo[3];
TypeInfo_EIPointLight* EIPointLight_GetTypeInfoStatic() { return &g_EIPointLight_TypeInfo[0]; }
