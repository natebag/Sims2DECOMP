// 0x80312198 EResource::GetTypeInfo (12B) const
struct TypeInfo_EResource { char data[256]; };
extern TypeInfo_EResource g_EResource_TypeInfo[3];
struct EResource_GTI { TypeInfo_EResource* GetTypeInfo() const; };
TypeInfo_EResource* EResource_GTI::GetTypeInfo() const { return &g_EResource_TypeInfo[0]; }
