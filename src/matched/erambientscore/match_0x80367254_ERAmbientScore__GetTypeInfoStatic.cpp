// 0x80367254 ERAmbientScore::GetTypeInfoStatic (12B)
struct TypeInfo_ERAmbientScore { char data[256]; };
extern TypeInfo_ERAmbientScore g_ERAmbientScore_TypeInfo[3];
TypeInfo_ERAmbientScore* ERAmbientScore_GetTypeInfoStatic() { return &g_ERAmbientScore_TypeInfo[0]; }
