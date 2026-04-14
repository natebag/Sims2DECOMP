// 0x8036B19C REffectsSequencer::GetReadVersion (12B)
struct RVBlock_REffectsSequencer { unsigned short ver[256]; };
extern RVBlock_REffectsSequencer g_REffectsSequencer_ReadVersion[3];
struct REffectsSequencer_GRV { unsigned short GetReadVersion(); };
unsigned short REffectsSequencer_GRV::GetReadVersion() { return g_REffectsSequencer_ReadVersion[0].ver[0]; }
