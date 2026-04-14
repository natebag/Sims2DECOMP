// 0x80228038 EILight::GetTypeInfoStatic (12B)
struct TypeInfo_EILight { char data[256]; };
extern TypeInfo_EILight g_EILight_TypeInfo[3];
TypeInfo_EILight* EILight_GetTypeInfoStatic() { return &g_EILight_TypeInfo[0]; }
