// 0x80367230 ERAmbientScore::GetTypeName (12B) const
extern char* g_ERAmbientScore_TypeName[3];
struct ERAmbientScore_GTN { const char* GetTypeName() const; };
const char* ERAmbientScore_GTN::GetTypeName() const { return g_ERAmbientScore_TypeName[0]; }
