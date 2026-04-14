// 0x8036B178 REffectsSequencer::GetTypeKey (12B) const
extern int g_REffectsSequencer_TypeKey[3];
struct REffectsSequencer_GTK { int GetTypeKey() const; };
int REffectsSequencer_GTK::GetTypeKey() const { return g_REffectsSequencer_TypeKey[0]; }
