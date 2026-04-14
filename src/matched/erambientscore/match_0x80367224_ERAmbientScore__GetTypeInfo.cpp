// 0x80367224 ERAmbientScore::GetTypeInfo (12B) const
struct TypeInfo_ERAmbientScore { char data[256]; };
extern TypeInfo_ERAmbientScore g_ERAmbientScore_TypeInfo[3];
struct ERAmbientScore_GTI { TypeInfo_ERAmbientScore* GetTypeInfo() const; };
TypeInfo_ERAmbientScore* ERAmbientScore_GTI::GetTypeInfo() const { return &g_ERAmbientScore_TypeInfo[0]; }
