// 0x802293D0 EInstance::GetTypeInfoStatic (12B)
struct TypeInfo_EInstance { char data[256]; };
extern TypeInfo_EInstance g_EInstance_TypeInfo[3];
TypeInfo_EInstance* EInstance_GetTypeInfoStatic() { return &g_EInstance_TypeInfo[0]; }
