// 0x8022A560 EIPointLight::GetTypeInfo (12B) const
struct TypeInfo_EIPointLight { char data[256]; };
extern TypeInfo_EIPointLight g_EIPointLight_TypeInfo[3];
struct EIPointLight_GTI { TypeInfo_EIPointLight* GetTypeInfo() const; };
TypeInfo_EIPointLight* EIPointLight_GTI::GetTypeInfo() const { return &g_EIPointLight_TypeInfo[0]; }
