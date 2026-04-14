// 0x8031B2A4 ERModel::GetTypeInfo (12B) const
struct TypeInfo_ERModel { char data[256]; };
extern TypeInfo_ERModel g_ERModel_TypeInfo[3];
struct ERModel_GTI { TypeInfo_ERModel* GetTypeInfo() const; };
TypeInfo_ERModel* ERModel_GTI::GetTypeInfo() const { return &g_ERModel_TypeInfo[0]; }
