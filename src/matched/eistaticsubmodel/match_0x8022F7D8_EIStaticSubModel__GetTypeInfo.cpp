// 0x8022F7D8 EIStaticSubModel::GetTypeInfo (12B) const
struct TypeInfo_EIStaticSubModel { char data[256]; };
extern TypeInfo_EIStaticSubModel g_EIStaticSubModel_TypeInfo[3];
struct EIStaticSubModel_GTI { TypeInfo_EIStaticSubModel* GetTypeInfo() const; };
TypeInfo_EIStaticSubModel* EIStaticSubModel_GTI::GetTypeInfo() const { return &g_EIStaticSubModel_TypeInfo[0]; }
