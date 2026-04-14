// 0x8036AC54 REffectsEmitter::GetTypeVersion (12B) const
struct VerBlock_REffectsEmitter { unsigned short ver[256]; };
extern VerBlock_REffectsEmitter g_REffectsEmitter_TypeVersion[3];
struct REffectsEmitter_GTV { unsigned short GetTypeVersion() const; };
unsigned short REffectsEmitter_GTV::GetTypeVersion() const { return g_REffectsEmitter_TypeVersion[0].ver[0]; }
