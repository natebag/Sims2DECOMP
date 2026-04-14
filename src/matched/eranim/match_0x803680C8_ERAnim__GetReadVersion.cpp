// 0x803680C8 ERAnim::GetReadVersion (12B)
struct RVBlock_ERAnim { unsigned short ver[256]; };
extern RVBlock_ERAnim g_ERAnim_ReadVersion[3];
struct ERAnim_GRV { unsigned short GetReadVersion(); };
unsigned short ERAnim_GRV::GetReadVersion() { return g_ERAnim_ReadVersion[0].ver[0]; }
