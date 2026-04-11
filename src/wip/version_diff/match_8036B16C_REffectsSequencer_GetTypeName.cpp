/* REffectsSequencer::GetTypeName(void) const - 0x8036B16C (12 bytes) */
// TU: reffects_sequencer

extern char REffectsSequencer_typeInfo_name;

struct REffectsSequencer {
    const char* GetTypeName() const;
};

const char* REffectsSequencer::GetTypeName() const {
    return &REffectsSequencer_typeInfo_name;
}
