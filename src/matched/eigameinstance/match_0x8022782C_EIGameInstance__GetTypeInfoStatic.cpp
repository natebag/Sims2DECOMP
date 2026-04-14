// 0x8022782C EIGameInstance::GetTypeInfoStatic (12B)
struct TypeInfo_EIGameInstance { char data[256]; };
extern TypeInfo_EIGameInstance g_EIGameInstance_TypeInfo[3];
TypeInfo_EIGameInstance* EIGameInstance_GetTypeInfoStatic() { return &g_EIGameInstance_TypeInfo[0]; }
