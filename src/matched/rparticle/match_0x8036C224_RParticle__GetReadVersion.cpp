// 0x8036C224 RParticle::GetReadVersion (12B)
struct RVBlock_RParticle { unsigned short ver[256]; };
extern RVBlock_RParticle g_RParticle_ReadVersion[3];
struct RParticle_GRV { unsigned short GetReadVersion(); };
unsigned short RParticle_GRV::GetReadVersion() { return g_RParticle_ReadVersion[0].ver[0]; }
