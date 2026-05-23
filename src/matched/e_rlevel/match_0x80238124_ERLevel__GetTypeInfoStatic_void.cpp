// 0x80238124 ERLevel::GetTypeInfoStatic(void) (12 B)
// lis 3,-32688; addi 3,3,-13080 => return &g_ERLevel_TypeInfo[0]
struct TypeInfo_ERLevel { char data[40]; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTIS { static TypeInfo_ERLevel* GetTypeInfoStatic(); };
TypeInfo_ERLevel* ERLevel_GTIS::GetTypeInfoStatic() { return &g_ERLevel_TypeInfo[0]; }
