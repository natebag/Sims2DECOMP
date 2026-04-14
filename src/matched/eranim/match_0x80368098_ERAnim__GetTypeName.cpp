// 0x80368098 ERAnim::GetTypeName (12B) const
extern char* g_ERAnim_TypeName[3];
struct ERAnim_GTN { const char* GetTypeName() const; };
const char* ERAnim_GTN::GetTypeName() const { return g_ERAnim_TypeName[0]; }
