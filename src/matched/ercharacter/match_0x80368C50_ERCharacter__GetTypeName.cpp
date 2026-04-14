// 0x80368C50 ERCharacter::GetTypeName (12B) const
extern char* g_ERCharacter_TypeName[3];
struct ERCharacter_GTN { const char* GetTypeName() const; };
const char* ERCharacter_GTN::GetTypeName() const { return g_ERCharacter_TypeName[0]; }
