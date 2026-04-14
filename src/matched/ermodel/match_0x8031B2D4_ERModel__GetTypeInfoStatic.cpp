// 0x8031B2D4 ERModel::GetTypeInfoStatic (12B)
struct TypeInfo_ERModel { char data[256]; };
extern TypeInfo_ERModel g_ERModel_TypeInfo[3];
TypeInfo_ERModel* ERModel_GetTypeInfoStatic() { return &g_ERModel_TypeInfo[0]; }
