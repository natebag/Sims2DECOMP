// 0x80368C44 ERCharacter::GetTypeInfo (12B) const
struct TypeInfo_ERCharacter { char data[256]; };
extern TypeInfo_ERCharacter g_ERCharacter_TypeInfo[3];
struct ERCharacter_GTI { TypeInfo_ERCharacter* GetTypeInfo() const; };
TypeInfo_ERCharacter* ERCharacter_GTI::GetTypeInfo() const { return &g_ERCharacter_TypeInfo[0]; }
