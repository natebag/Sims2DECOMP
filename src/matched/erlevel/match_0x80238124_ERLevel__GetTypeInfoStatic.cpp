// 0x80238124 ERLevel::GetTypeInfoStatic (12B)
struct TypeInfo_ERLevel { char data[256]; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
TypeInfo_ERLevel* ERLevel_GetTypeInfoStatic() { return &g_ERLevel_TypeInfo[0]; }
