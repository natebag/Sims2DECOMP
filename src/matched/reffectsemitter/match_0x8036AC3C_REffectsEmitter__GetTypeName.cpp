// 0x8036AC3C REffectsEmitter::GetTypeName (12B) const
extern char* g_REffectsEmitter_TypeName[3];
struct REffectsEmitter_GTN { const char* GetTypeName() const; };
const char* REffectsEmitter_GTN::GetTypeName() const { return g_REffectsEmitter_TypeName[0]; }
