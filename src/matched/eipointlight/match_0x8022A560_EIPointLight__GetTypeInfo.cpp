// 0x8022A560 EIPointLight::GetTypeInfo(void) const (12B)
struct TypeInfo_EIPL { char data[256]; };
extern TypeInfo_EIPL g_EIPL_TypeInfo[3];
struct EIPL_GTI { TypeInfo_EIPL* GetTypeInfo() const; };
TypeInfo_EIPL* EIPL_GTI::GetTypeInfo() const { return &g_EIPL_TypeInfo[0]; }
