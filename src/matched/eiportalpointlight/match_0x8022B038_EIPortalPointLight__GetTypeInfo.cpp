// 0x8022B038 EIPortalPointLight::GetTypeInfo(void) const (12B)
struct TypeInfo_EIPPL { char data[256]; };
extern TypeInfo_EIPPL g_EIPPL_TypeInfo[3];
struct EIPPL_GTI { TypeInfo_EIPPL* GetTypeInfo() const; };
TypeInfo_EIPPL* EIPPL_GTI::GetTypeInfo() const { return &g_EIPPL_TypeInfo[0]; }
