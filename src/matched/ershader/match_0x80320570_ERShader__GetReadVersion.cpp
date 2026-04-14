// 0x80320570 ERShader::GetReadVersion (12B)
struct RVBlock_ERShader { unsigned short ver[256]; };
extern RVBlock_ERShader g_ERShader_ReadVersion[3];
struct ERShader_GRV { unsigned short GetReadVersion(); };
unsigned short ERShader_GRV::GetReadVersion() { return g_ERShader_ReadVersion[0].ver[0]; }
