// 0x803680BC ERAnim::GetTypeInfoStatic (12B)
struct TypeInfo_ERAnim { char data[256]; };
extern TypeInfo_ERAnim g_ERAnim_TypeInfo[3];
TypeInfo_ERAnim* ERAnim_GetTypeInfoStatic() { return &g_ERAnim_TypeInfo[0]; }
