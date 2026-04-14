// 0x80053F88 ISimsWallObjectModel::GetTypeInfoStatic (12B)
struct TypeInfo_ISimsWallObjectModel { char data[256]; };
extern TypeInfo_ISimsWallObjectModel g_ISimsWallObjectModel_TypeInfo[3];
TypeInfo_ISimsWallObjectModel* ISimsWallObjectModel_GetTypeInfoStatic() { return &g_ISimsWallObjectModel_TypeInfo[0]; }
