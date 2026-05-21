// 0x80226F4C EIAmbLight::GetTypeInfoStatic(void) (12B)
struct TypeInfo_EIAmbLight { char data[256]; };
extern TypeInfo_EIAmbLight g_EIAmbLight_TypeInfo[3];
TypeInfo_EIAmbLight* EIAmbLight_GetTypeInfoStatic() { return &g_EIAmbLight_TypeInfo[0]; }
