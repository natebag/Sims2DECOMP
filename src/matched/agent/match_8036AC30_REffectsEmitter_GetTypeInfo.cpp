// REffectsEmitter::GetTypeInfo - 0x8036AC30 (12 bytes)
// TU: reffects_emitter

void* REffectsEmitter_GetTypeInfo(void* self) {
    extern int REffectsEmitter_s_typeInfo;
    return &REffectsEmitter_s_typeInfo;
}
