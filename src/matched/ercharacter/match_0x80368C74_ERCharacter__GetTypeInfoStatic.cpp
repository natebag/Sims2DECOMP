// 0x80368C74 ERCharacter::GetTypeInfoStatic (12B)
struct TypeInfo_ERCharacter { char data[256]; };
extern TypeInfo_ERCharacter g_ERCharacter_TypeInfo[3];
TypeInfo_ERCharacter* ERCharacter_GetTypeInfoStatic() { return &g_ERCharacter_TypeInfo[0]; }
