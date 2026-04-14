// 0x8022E070 EIStaticModel::GetTypeInfo (12B) const
struct TypeInfo_EIStaticModel { char data[256]; };
extern TypeInfo_EIStaticModel g_EIStaticModel_TypeInfo[3];
struct EIStaticModel_GTI { TypeInfo_EIStaticModel* GetTypeInfo() const; };
TypeInfo_EIStaticModel* EIStaticModel_GTI::GetTypeInfo() const { return &g_EIStaticModel_TypeInfo[0]; }
