/* REffectsSequencer::GetTypeInfo(void) const - 0x8036B160 (12 bytes) */
// TU: reffects_sequencer

struct TypeInfo;

extern TypeInfo REffectsSequencer_typeInfo;

struct REffectsSequencer {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* REffectsSequencer::GetTypeInfo() const {
    return &REffectsSequencer_typeInfo;
}
