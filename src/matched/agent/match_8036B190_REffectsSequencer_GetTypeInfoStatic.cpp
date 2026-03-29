/* REffectsSequencer::GetTypeInfoStatic(void) - 0x8036B190 (12 bytes) */
// TU: reffects_sequencer

struct TypeInfo;

extern TypeInfo REffectsSequencer_typeInfo;

struct REffectsSequencer {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* REffectsSequencer::GetTypeInfoStatic() {
    return &REffectsSequencer_typeInfo;
}
