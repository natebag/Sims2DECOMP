// 0x803680B0 ERAnim::GetTypeVersion (12B) const
struct VerBlock_ERAnim { unsigned short ver[256]; };
extern VerBlock_ERAnim g_ERAnim_TypeVersion[3];
struct ERAnim_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERAnim_GTV::GetTypeVersion() const { return g_ERAnim_TypeVersion[0].ver[0]; }
