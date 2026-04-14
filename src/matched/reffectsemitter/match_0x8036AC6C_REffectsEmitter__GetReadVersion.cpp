// 0x8036AC6C REffectsEmitter::GetReadVersion (12B)
struct RVBlock_REffectsEmitter { unsigned short ver[256]; };
extern RVBlock_REffectsEmitter g_REffectsEmitter_ReadVersion[3];
struct REffectsEmitter_GRV { unsigned short GetReadVersion(); };
unsigned short REffectsEmitter_GRV::GetReadVersion() { return g_REffectsEmitter_ReadVersion[0].ver[0]; }
