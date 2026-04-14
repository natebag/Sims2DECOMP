// 0x80368580 ERBinary::GetTypeInfoStatic (12B)
struct TypeInfo_ERBinary { char data[256]; };
extern TypeInfo_ERBinary g_ERBinary_TypeInfo[3];
TypeInfo_ERBinary* ERBinary_GetTypeInfoStatic() { return &g_ERBinary_TypeInfo[0]; }
