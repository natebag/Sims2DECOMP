// 0x80227448 EIDirLight::GetTypeInfoStatic (12B)
struct TypeInfo_EIDirLight { char data[256]; };
extern TypeInfo_EIDirLight g_EIDirLight_TypeInfo[3];
TypeInfo_EIDirLight* EIDirLight_GetTypeInfoStatic() { return &g_EIDirLight_TypeInfo[0]; }
