// 0x80367248 ERAmbientScore::GetTypeVersion (12B) const
struct VerBlock_ERAmbientScore { unsigned short ver[256]; };
extern VerBlock_ERAmbientScore g_ERAmbientScore_TypeVersion[3];
struct ERAmbientScore_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERAmbientScore_GTV::GetTypeVersion() const { return g_ERAmbientScore_TypeVersion[0].ver[0]; }
