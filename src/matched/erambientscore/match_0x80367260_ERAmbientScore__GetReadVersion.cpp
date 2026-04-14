// 0x80367260 ERAmbientScore::GetReadVersion (12B)
struct RVBlock_ERAmbientScore { unsigned short ver[256]; };
extern RVBlock_ERAmbientScore g_ERAmbientScore_ReadVersion[3];
struct ERAmbientScore_GRV { unsigned short GetReadVersion(); };
unsigned short ERAmbientScore_GRV::GetReadVersion() { return g_ERAmbientScore_ReadVersion[0].ver[0]; }
