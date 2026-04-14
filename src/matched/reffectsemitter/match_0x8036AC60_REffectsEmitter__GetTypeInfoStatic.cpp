// 0x8036AC60 REffectsEmitter::GetTypeInfoStatic (12B)
struct TypeInfo_REffectsEmitter { char data[256]; };
extern TypeInfo_REffectsEmitter g_REffectsEmitter_TypeInfo[3];
TypeInfo_REffectsEmitter* REffectsEmitter_GetTypeInfoStatic() { return &g_REffectsEmitter_TypeInfo[0]; }
