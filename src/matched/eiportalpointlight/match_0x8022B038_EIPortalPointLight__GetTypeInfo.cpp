// 0x8022B038 EIPortalPointLight::GetTypeInfo (12B) const
struct TypeInfo_EIPortalPointLight { char data[256]; };
extern TypeInfo_EIPortalPointLight g_EIPortalPointLight_TypeInfo[3];
struct EIPortalPointLight_GTI { TypeInfo_EIPortalPointLight* GetTypeInfo() const; };
TypeInfo_EIPortalPointLight* EIPortalPointLight_GTI::GetTypeInfo() const { return &g_EIPortalPointLight_TypeInfo[0]; }
