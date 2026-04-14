// 0x8022E0A0 EIStaticModel::GetTypeInfoStatic (12B)
struct TypeInfo_EIStaticModel { char data[256]; };
extern TypeInfo_EIStaticModel g_EIStaticModel_TypeInfo[3];
TypeInfo_EIStaticModel* EIStaticModel_GetTypeInfoStatic() { return &g_EIStaticModel_TypeInfo[0]; }
