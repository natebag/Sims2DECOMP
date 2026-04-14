// 0x803680A4 ERAnim::GetTypeKey (12B) const
extern int g_ERAnim_TypeKey[3];
struct ERAnim_GTK { int GetTypeKey() const; };
int ERAnim_GTK::GetTypeKey() const { return g_ERAnim_TypeKey[0]; }
