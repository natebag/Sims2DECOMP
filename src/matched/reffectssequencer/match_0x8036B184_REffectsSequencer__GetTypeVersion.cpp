// 0x8036B184 REffectsSequencer::GetTypeVersion (12B) const
struct VerBlock_REffectsSequencer { unsigned short ver[256]; };
extern VerBlock_REffectsSequencer g_REffectsSequencer_TypeVersion[3];
struct REffectsSequencer_GTV { unsigned short GetTypeVersion() const; };
unsigned short REffectsSequencer_GTV::GetTypeVersion() const { return g_REffectsSequencer_TypeVersion[0].ver[0]; }
