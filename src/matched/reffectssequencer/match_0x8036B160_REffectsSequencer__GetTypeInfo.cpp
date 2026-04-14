// 0x8036B160 REffectsSequencer::GetTypeInfo (12B) const
struct TypeInfo_REffectsSequencer { char data[256]; };
extern TypeInfo_REffectsSequencer g_REffectsSequencer_TypeInfo[3];
struct REffectsSequencer_GTI { TypeInfo_REffectsSequencer* GetTypeInfo() const; };
TypeInfo_REffectsSequencer* REffectsSequencer_GTI::GetTypeInfo() const { return &g_REffectsSequencer_TypeInfo[0]; }
