// 0x8036AC30 REffectsEmitter::GetTypeInfo (12B) const
struct TypeInfo_REffectsEmitter { char data[256]; };
extern TypeInfo_REffectsEmitter g_REffectsEmitter_TypeInfo[3];
struct REffectsEmitter_GTI { TypeInfo_REffectsEmitter* GetTypeInfo() const; };
TypeInfo_REffectsEmitter* REffectsEmitter_GTI::GetTypeInfo() const { return &g_REffectsEmitter_TypeInfo[0]; }
