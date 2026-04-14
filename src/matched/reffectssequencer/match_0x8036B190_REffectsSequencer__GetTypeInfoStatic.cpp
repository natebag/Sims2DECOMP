// 0x8036B190 REffectsSequencer::GetTypeInfoStatic (12B)
struct TypeInfo_REffectsSequencer { char data[256]; };
extern TypeInfo_REffectsSequencer g_REffectsSequencer_TypeInfo[3];
TypeInfo_REffectsSequencer* REffectsSequencer_GetTypeInfoStatic() { return &g_REffectsSequencer_TypeInfo[0]; }
