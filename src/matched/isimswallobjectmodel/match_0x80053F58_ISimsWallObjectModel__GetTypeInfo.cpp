// 0x80053F58 ISimsWallObjectModel::GetTypeInfo (12B) const
struct TypeInfo_ISimsWallObjectModel { char data[256]; };
extern TypeInfo_ISimsWallObjectModel g_ISimsWallObjectModel_TypeInfo[3];
struct ISimsWallObjectModel_GTI { TypeInfo_ISimsWallObjectModel* GetTypeInfo() const; };
TypeInfo_ISimsWallObjectModel* ISimsWallObjectModel_GTI::GetTypeInfo() const { return &g_ISimsWallObjectModel_TypeInfo[0]; }
