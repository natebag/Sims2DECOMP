// 0x8022F808 EIStaticSubModel::GetTypeInfoStatic (12B)
struct TypeInfo_EIStaticSubModel { char data[256]; };
extern TypeInfo_EIStaticSubModel g_EIStaticSubModel_TypeInfo[3];
TypeInfo_EIStaticSubModel* EIStaticSubModel_GetTypeInfoStatic() { return &g_EIStaticSubModel_TypeInfo[0]; }
