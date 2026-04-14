// 0x8036808C ERAnim::GetTypeInfo (12B) const
struct TypeInfo_ERAnim { char data[256]; };
extern TypeInfo_ERAnim g_ERAnim_TypeInfo[3];
struct ERAnim_GTI { TypeInfo_ERAnim* GetTypeInfo() const; };
TypeInfo_ERAnim* ERAnim_GTI::GetTypeInfo() const { return &g_ERAnim_TypeInfo[0]; }
