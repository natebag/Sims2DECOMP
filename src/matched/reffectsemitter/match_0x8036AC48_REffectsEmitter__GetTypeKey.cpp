// 0x8036AC48 REffectsEmitter::GetTypeKey (12B) const
extern int g_REffectsEmitter_TypeKey[3];
struct REffectsEmitter_GTK { int GetTypeKey() const; };
int REffectsEmitter_GTK::GetTypeKey() const { return g_REffectsEmitter_TypeKey[0]; }
