// 0x8036B16C REffectsSequencer::GetTypeName (12B) const
extern char* g_REffectsSequencer_TypeName[3];
struct REffectsSequencer_GTN { const char* GetTypeName() const; };
const char* REffectsSequencer_GTN::GetTypeName() const { return g_REffectsSequencer_TypeName[0]; }
