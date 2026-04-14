// 0x80227418 EIDirLight::GetTypeInfo (12B) const
struct TypeInfo_EIDirLight { char data[256]; };
extern TypeInfo_EIDirLight g_EIDirLight_TypeInfo[3];
struct EIDirLight_GTI { TypeInfo_EIDirLight* GetTypeInfo() const; };
TypeInfo_EIDirLight* EIDirLight_GTI::GetTypeInfo() const { return &g_EIDirLight_TypeInfo[0]; }
