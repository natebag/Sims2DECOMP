// 0x80320558 ERShader::GetTypeVersion (12B) const
struct VerBlock_ERShader { unsigned short ver[256]; };
extern VerBlock_ERShader g_ERShader_TypeVersion[3];
struct ERShader_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERShader_GTV::GetTypeVersion() const { return g_ERShader_TypeVersion[0].ver[0]; }
