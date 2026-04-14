// 0x80228008 EILight::GetTypeInfo (12B) const
struct TypeInfo_EILight { char data[256]; };
extern TypeInfo_EILight g_EILight_TypeInfo[3];
struct EILight_GTI { TypeInfo_EILight* GetTypeInfo() const; };
TypeInfo_EILight* EILight_GTI::GetTypeInfo() const { return &g_EILight_TypeInfo[0]; }
