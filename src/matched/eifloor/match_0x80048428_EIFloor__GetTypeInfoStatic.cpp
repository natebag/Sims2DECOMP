// 0x80048428 EIFloor::GetTypeInfoStatic (12B)
struct TypeInfo_EIFloor { char data[256]; };
extern TypeInfo_EIFloor g_EIFloor_TypeInfo[3];
TypeInfo_EIFloor* EIFloor_GetTypeInfoStatic() { return &g_EIFloor_TypeInfo[0]; }
