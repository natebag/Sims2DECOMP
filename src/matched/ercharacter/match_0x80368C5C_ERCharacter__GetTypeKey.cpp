// 0x80368C5C ERCharacter::GetTypeKey (12B) const
extern int g_ERCharacter_TypeKey[3];
struct ERCharacter_GTK { int GetTypeKey() const; };
int ERCharacter_GTK::GetTypeKey() const { return g_ERCharacter_TypeKey[0]; }
