/* REffectsSequencer::GetTypeKey(void) const - 0x8036B178 (12 bytes) */
// TU: reffects_sequencer

extern unsigned int REffectsSequencer_typeInfo_key;

struct REffectsSequencer {
    unsigned int GetTypeKey() const;
};

unsigned int REffectsSequencer::GetTypeKey() const {
    return REffectsSequencer_typeInfo_key;
}
