// 0x803121C8 EResource::GetTypeInfoStatic (12B)
struct TypeInfo_EResource { char data[256]; };
extern TypeInfo_EResource g_EResource_TypeInfo[3];
TypeInfo_EResource* EResource_GetTypeInfoStatic() { return &g_EResource_TypeInfo[0]; }
